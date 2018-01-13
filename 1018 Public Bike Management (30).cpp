#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

const int N = 501, INF = 1000000000;
int minBring, minTake;
stack<int> route;
int c[N];
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
    void init(int nn)
    {
        n = nn;
        edges.clear();
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
    int Dfs(int from, int to, int cnt, int bring)
    {
        if(from == to) {
            cnt += c[from];
            bring = max(-cnt, bring);
            if(bring < minBring) {
                minBring = bring;
                minTake = max(0, bring + cnt);
                while(!route.empty())
                    route.pop();
                route.push(from);
                return 1;
            }
            if(bring == minBring && max(bring + cnt, 0) < minTake) {
                minTake = max(0, bring + cnt);
                while(!route.empty())
                    route.pop();
                route.push(from);
                return 1;
            }
            return 0;
        }
        int isS = 0;
        cnt += c[from];
        for(int i = 0; i < G[from].size(); i++) {
            Edge &e = edges[G[from][i]];
            if(d[e.to] == d[from] + e.dis) {
                if(Dfs(e.to, to, cnt, max(bring, -cnt))) {
                    route.push(from);
                    isS = 1;
                }
            }
        }
        if(isS) return 1;
        else return 0;
    }
};
int Cmax, n, sp, m, dis;
Graph g;
int main()
{
    scanf("%d%d%d%d\n", &Cmax, &n, &sp, &m);
    Cmax /= 2;
    n++;
    memset(c, 0, sizeof(c));
    g.init(n);
    for(int i = 1; i < n; i++) {
        scanf("%d", &c[i]);
        c[i] -= Cmax;
    }
    for(int i = 0; i < m; i++) {
        int u, v, t;
        scanf("%d%d%d", &u, &v, &t);
        g.AddEdge(u, v, t);
    }
    dis = g.Mindis(0, sp);
    minBring = INF;
    minTake = INF;
    g.Dfs(0, sp, 0, 0);

    printf("%d", minBring);
    printf(" 0");
    route.pop();
    while(!route.empty()) {
        printf("->%d", route.top());
        route.pop();
    }
    printf(" %d", minTake);

    return 0;
}