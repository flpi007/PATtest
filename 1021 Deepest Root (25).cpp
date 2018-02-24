#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
using namespace std;

const int N = 10000;
struct Edge {
    int from, to;
    Edge(int a, int b): from(a), to(b) {}
};
struct Graph {
    vector<Edge> edges;
    vector<int> G[N];
    int m;
    int d[N];
    void AddEdge(int u, int v)
    {
        edges.push_back(Edge(u, v));
        edges.push_back(Edge(v, u));
        m = edges.size();
        G[u].push_back(m - 2);
        G[v].push_back(m - 1);
    }
    int Bfs(int x)
    {
        queue<int> q;
        q.push(x);
        d[x] = 0;
        int dis, u;
        while(!q.empty()) {
            u = q.front(); q.pop();
            dis = d[u];
            for(int i = 0; i < G[u].size(); i++) {
                Edge &e = edges[G[u][i]];
                if(d[e.to] == -1) {
                    q.push(e.to);
                    d[e.to] = dis + 1;
                }
            }
        }
        return u;
    }
    void clearDis(){
        memset(d, -1, sizeof(d));
    }
};
int n;
Graph g;
int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        g.AddEdge(u - 1, v  - 1);
    }
    int color = 0, x;
    g.clearDis();
    for(int i = 0; i < n; i++) {
        // printf("i:%d\n", i);
        if(g.d[i] == -1) {
            x = g.Bfs(i);
            color++;
        }
    }
    if(color > 1) {
        printf("Error: %d components\n", color);
    } else {
        set<int> list;
        g.clearDis();
        int y = g.Bfs(x);
        for(int i = 0; i<n; i++){
            if(g.d[i] == g.d[y]){
                list.insert(i);
            }
        }
        g.clearDis();
        int x = g.Bfs(y);
        for(int i = 0; i<n; i++){
            if(g.d[i] == g.d[x]){
                list.insert(i);
            }
        }
        for(auto i = list.begin(); i != list.end(); i++) {
            printf("%d\n", (*i) + 1);
        }
    }
    return 0;
}