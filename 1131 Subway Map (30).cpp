#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

const int N = 100, M = 100, INF = 1000000000;
struct Edge {
    int from, to, dis;
    Edge(int f, int t, int d)
    {
        from = f;
        to = t;
        dis = d;
    }
};
struct Graph {
    int m;
    int d[N * M];
    vector<Edge> edges;
    vector<int> G[N * M];
    void AddEdge(int f, int t, int dis)
    {
        edges.push_back(Edge(f, t, dis));
        edges.push_back(Edge(t, f, dis));
        m = edges.size();
        G[f].push_back(m - 2);
        G[t].push_back(m - 1);
    }
    void MinDis(int s)
    {
        for(int i = 0; i < N * M; i++) {
            d[i] = INF;
        }
        d[s] = 0;
        int inq[N * M];
        memset(inq, 0, sizeof(inq));
        inq[s] = 1;
        queue<int> q;
        q.push(s);
        while(!q.empty()) {
            int u = q.front(); q.pop();
            inq[u] = 0;
            for(int i = 0; i < G[u].size(); i++) {
                Edge &e = edges[G[u][i]];
                if(d[u] + e.dis < d[e.to]) {
                    d[e.to] = d[u] + e.dis;
                    if(!inq[e.to]) {
                        q.push(e.to);
                        inq[e.to] = 1;
                    }
                }
            }
        }
    }
};
int n, k;
vector<int> line[N];
Graph g;

int bestc;
vector<int> path;
set<int> d[N * M];
int ss, tt, len;
int vis[N * M];
int getID(int a)
{
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < line[i].size(); j++) {
            if(line[i][j] == a)
                return i * M + j;
        }
    }
    return -1;
}
int getNum(int a)
{
    return line[a / M][a % M];
}
int dfs(int u, int dis, int cnt)
{
    if(getNum(u) == getNum(tt)) {
        if(cnt < bestc) {
            bestc = cnt;
            path.clear();
            path.push_back(u);
            return 1;
        } else {
            return 0;
        }
    }
    int better = 0;
    vis[u] = 1;
    for(int i = 0; i < g.G[u].size(); i++) {
        Edge &e = g.edges[g.G[u][i]];
        if(dis + e.dis == g.d[e.to]\
           && !vis[e.to]\
           && g.d[e.to] <= len\
           && cnt <= bestc) {
            int inc = (d[u].find(e.to) != d[u].end()) ? 1 : 0;
            if(dis == 0 && getNum(u) == getNum(e.to)) {
                inc = 0;
            }
            if(dfs(e.to, dis + e.dis, cnt + inc)) {
                path.push_back(u);
                better = 1;
            }
        }
    }
    vis[u] = 0;
    return better;
}
void outputPath()
{
    reverse(path.begin(), path.end());
    int f, e;
    for(f = 0; \
        f < path.size() - 1 \
        && getNum(path[f]) == getNum(path[f + 1]); \
        f++);
    e = f + 1;
    int last = path[f] / M + 1;
    while(true) {
        while(e < path.size() \
              && (path[e] / M == path[f] / M \
                  || getNum(path[e]) == getNum(path[f]))) {
            e++;
        }
        printf("Take Line#%d from %04d to %04d.\n", \
               last, getNum(path[f]), getNum(path[e - 1]));
        while(e < path.size() && getNum(path[e - 1]) == getNum(path[e])) {
            e++;
        }
        if(e == path.size())
            break;
        f = e - 1;
        last = path[f] / M + 1;
    }
}
int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int m;
        scanf("%d", &m);
        for(int j = 0; j < m; j++) {
            int t;
            scanf("%d", &t);
            line[i].push_back(t);
            for(int k = 0; k < i; k++) {
                for(int x = 0; x < line[k].size(); x++) {
                    if(line[k][x] == line[i][j]) {
                        g.AddEdge(k * M + x, i * M + j, 0); //cross nodes
                        d[k * M + x].insert(i * M + j);
                        d[i * M + j].insert(k * M + x);
                    }
                }
            }
        }
        for(int j = 1; j < m; j++) {
            g.AddEdge(i * M + j - 1, i * M + j, 1); //nodes in a line
        }
    }


    scanf("%d", &k);
    for(int i = 0; i < k; i++) {
        int s, t;
        scanf("%d %d", &s, &t);
        ss = getID(s), tt = getID(t);
        g.MinDis(ss);

        bestc = INF;
        memset(vis, 0, sizeof(vis));
        path.clear();
        len = g.d[tt];
        dfs(ss, 0, 0);
        printf("%d\n", len);
        outputPath();
    }
    return 0;
}