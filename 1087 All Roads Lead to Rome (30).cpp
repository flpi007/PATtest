#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

const int N = 201, L = 4, INF = 1000000000;
const char *ROM = "ROM";

int num[26 * 26 * 26];
char City[N][L];
int maxH, cnt, cost;
double aveH;
stack<int> route;

int Encode(const char *s)
{
    int a = 0;
    for(int i = 0; i < 3; i++)
        a = a * 26 + s[i] - 'A';
    return a;
}
struct Edge {
    int from, to, dis;
    Edge(int f, int t, int d): from(f), to(t), dis(d) {}
};
struct Graph {
    int n, m;
    vector<int> G[N];
    vector<Edge> edges;
    int inq[N];
    int d[N];
    int happ[N];
    void init(int nn)
    {
        n = nn;
        edges.clear();
        memset(happ, 0, sizeof(happ));
        for(int i = 0; i < n; i++)
            G[i].clear();
    }
    void AddEdge(int f, int t, int d)
    {
        edges.push_back(Edge(f, t, d));
        edges.push_back(Edge(t, f, d));
        m = edges.size();
        G[f].push_back(m - 2);
        G[t].push_back(m - 1);
    }
    int Mindis(int s, int t)
    {
        memset(inq, 0, sizeof(inq));
        for(int i = 0; i < n; i++)
            d[i] = INF;
        d[s] = 0;
        queue<int> q;
        inq[s] = 1;
        q.push(s);
        while(!q.empty()) {
            int u = q.front(); q.pop();
            inq[u] = 0;
            for(int i = 0; i < G[u].size(); i++) {
                Edge &e = edges[G[u][i]];
                if(d[e.to] > d[u] + e.dis) {
                    d[e.to] = d[u] + e.dis;
                    if(!inq[e.to]) {
                        inq[e.to] = 1;
                        q.push(e.to);
                    }
                }
            }
        }
        return d[t];
    }
    int Dfs(int from, int depth, int h)
    {
        if(from == num[Encode(ROM)]) {
            cnt++;
            h += happ[from];
            if(h < maxH)
                return 0;
            if(h > maxH) {
                maxH = h;
                aveH = h / double(depth);
                while(!route.empty())
                    route.pop();
                route.push(from);
            }else if(h == maxH && (h / double(depth)) > aveH) {
                aveH = h / double(depth);
                while(!route.empty())
                    route.pop();
                route.push(from);
            }
            return 1;
        }
        int better = 0;
        for(int i = 0; i < G[from].size(); i++) {
            Edge &e = edges[G[from][i]];
            if(d[e.to] <= cost && (d[e.to] == d[from] + e.dis)) {
                if(Dfs(e.to, depth + 1, h + happ[from])) {
                    route.push(from);
                    better = 1;
                }
            }
        }
        if(better) return 1;
        else return 0;
    }
};
int n, m, h, nNode = 0;
Graph g;
inline void mapCity(char *s){
    memcpy(City[nNode], s, L);
    num[Encode(s)] = nNode;
    nNode++;
}
int main()
{
    char s[L], s1[L], s2[L];
    memset(num, 0, sizeof(num));
    scanf("%d %d %s\n", &n, &m, s);
    g.init(n);
    g.happ[0] = 0;
    mapCity(s);
    for(int i = 1; i < n; i++) {
        scanf("%s %d\n", s1, &h);
        g.happ[nNode] = h;
        mapCity(s1);
    }
    int d;
    for(int i = 0; i < m; i++) {
        scanf("%s %s %d\n", s1, s2, &d);
        // printf("%d %d\n", num[Encode(s1)], num[Encode(s2)]);
        g.AddEdge(num[Encode(s1)], num[Encode(s2)], d);
    }
    cost = g.Mindis(0, num[Encode(ROM)]);
    maxH = 0;
    aveH = 0.0;
    cnt = 0;
    g.Dfs(0, 0, 0);
    printf("%d %d %d %d\n", cnt, cost, maxH, int(aveH));
    printf("%s", s);
    route.pop();
    while(!route.empty()) {
        printf("->%s", City[route.top()]);
        route.pop();
    }
    printf("\n");
    return 0;
}