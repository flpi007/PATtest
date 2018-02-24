#include <cstdio>
#include <vector>
#include <cstring>
#include <stack>
using namespace std;

const int N = 1000;
struct Edge {
    int from, to;
    Edge(int f, int t): from(f), to(t) {};
};
struct Graph {
    vector<Edge> edges;
    vector<int> G[N];
    int n, m;
    void AddEdge(int f, int t)
    {
        edges.push_back(Edge(f, t));
        edges.push_back(Edge(t, f));
        m = edges.size();
        G[f].push_back(m - 2);
        G[t].push_back(m - 1);
    }
};
struct Tarjan {
    int dfn[N], low[N], sub[N], isroot[N];
    int n, dfsCnt, colorCnt;
    Graph *g;
    Tarjan(Graph &graph)
    {
        memset(dfn, 0, sizeof(dfn));
        memset(sub, 0, sizeof(sub));
        memset(isroot, 0, sizeof(isroot));
        memset(low, -1, sizeof(low));
        n = graph.n;
        g = &graph;
        dfsCnt = 0; colorCnt = 0;
        for(int i = 0; i < n; i++) {
            if(!dfn[i]) {
                colorCnt++;
                isroot[i] = 1;
                Dfs(i);
            }
        }
    }
    void Dfs(int x)
    {
        // printf("dfs:%d\n", x);
        dfn[x] = ++dfsCnt;
        low[x] = dfn[x];
        for(int i = 0; i < g->G[x].size(); i++) {
            Edge &e = g->edges[g->G[x][i]];
            if(!dfn[e.to]) {
                Dfs(e.to);
                sub[x]++;
                low[x] = min(low[x], low[e.to]);
            } else {
                low[x] = min(low[x], dfn[e.to]);
            }
        }
    }
    int CutCnt(int x)
    {
        if(isroot[x]) {
            return sub[x];
        } else {
            int t = 0;
            for(int i = 0; i < g->G[x].size(); i++) {
                Edge &e = g->edges[g->G[x][i]];
                // printf("%d->%d\n", x + 1, e.to + 1);
                // printf("dfn:%d low:%d\n", dfn[x], low[e.to]);
                if(low[e.to] >= dfn[x]) {
                    t++;
                }
            }
            return t + 1;
        }
    }
};
int n, m, k;
Graph graph;
int main()
{
    scanf("%d%d%d", &n, &m, &k);
    graph.n = n;
    for(int i = 0; i < m; i++) {
        int f, t;
        scanf("%d%d", &f, &t);
        graph.AddEdge(f - 1, t - 1);
    }
    Tarjan tarjan(graph);
    int b = tarjan.colorCnt - 1;
    for(int i = 0; i < k; i++) {
        int v;
        scanf("%d", &v);
        v--;
        int a = tarjan.CutCnt(v);
        // printf("%d a:%d\n", v + 1, a);
        printf("%d\n", a - 1 + b);
    }
    return 0;
}