#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

const int N = 507, INF = 1000000000;
struct Edge {
    int from, to, dis, time;
    Edge(int f, int t, int d, int ti): \
        from(f), to(t), dis(d), time(ti) {}
};
inline int TraitsDis(const Edge &e)
{
    return e.dis;
}
inline int TraitsTime(const Edge &e)
{
    return e.time;
}
inline int TraitsInter(const Edge &e)
{
    return 1;
}
struct Graph {
    int n, m, t;
    int dis[N], time[N];
    vector<Edge> edges;
    vector<int> G[N];
    void AddEdge(int from, int to, int one, int len, int t)
    {
        if(one) {
            edges.push_back(Edge(from, to, len, t));
            m = edges.size();
            G[from].push_back(m - 1);
        } else {
            edges.push_back(Edge(from, to, len, t));
            edges.push_back(Edge(to, from, len, t));
            m = edges.size();
            G[from].push_back(m - 2);
            G[to].push_back(m - 1);
        }
    }
    void MinDis(int s, int val(const Edge &), int *d)
    {
        for(int i = 0; i < n; i++) {
            d[i] = INF;
        }
        int inq[N];
        memset(inq, 0, sizeof(inq));
        queue<int> q;
        inq[s] = 1;
        d[s] = 0;
        q.push(s);
        while(!q.empty()) {
            int u = q.front(); q.pop();
            inq[u] = 0;
            for(int i = 0; i < G[u].size(); i++) {
                Edge &e = edges[G[u][i]];
                if(d[u] + val(e) < d[e.to]) {
                    d[e.to] = d[u] + val(e);
                    if(!inq[e.to]) {
                        inq[e.to] = 1;
                        q.push(e.to);
                    }
                }
            }
        }
    }
    struct Best {
        int opt;
        int *d;
        stack<int> path;
        int (*val)(const Edge &e);
        int (*inc)(const Edge &e);
        Best()
        {
            opt = INF;
        }
    };
    Best bestd, bestt;
    int dfs(Best &best, int u, int sum)
    {
        if(u == t) {
            if(sum < best.opt) {
                best.opt = sum;
                while(!best.path.empty()) {
                    best.path.pop();
                }
                best.path.push(u);
                return 1;
            } else {
                return 0;
            }
        }
        int better = 0;
        for(int i = 0; i < G[u].size(); i++) {
            Edge &e = edges[G[u][i]];
            if(best.d[u] + best.val(e) == best.d[e.to] && \
               dfs(best, e.to, sum + best.inc(e))) {
                best.path.push(u);
                better = 1;
            }
        }
        return better;
    }
};
int n, m, s, t;
Graph g;
void printpath(stack<int> &path)
{
    int first = 1;
    while(!path.empty()) {
        int u = path.top(); path.pop();
        if(!first) {
            printf(" ->");
        }
        printf(" %d", u);
        first = 0;
    }
}
bool identical()
{
    stack<int> a = g.bestd.path, b = g.bestt.path;
    if(a.size() != b.size()) {
        return true;
    } else {
        while(!a.empty() && !b.empty()) {
            int u = a.top(); a.pop();
            int v = b.top(); b.pop();
            if(u != v){
                return true;
            }
        }
        return false;
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    g.n = n;
    for(int i = 0; i < m; i++) {
        int from, to, one, len, t;
        scanf("%d%d%d%d%d", &from, &to, &one, &len, &t);
        g.AddEdge(from, to, one, len, t);
    }
    scanf("%d%d", &s, &t);
    g.t = t;
    g.MinDis(s, TraitsDis, g.dis);
    g.MinDis(s, TraitsTime, g.time);

    g.bestd.inc = TraitsTime;
    g.bestd.val = TraitsDis;
    g.bestd.d = g.dis;
    g.dfs(g.bestd, s, 0);
    g.bestt.inc = TraitsInter;
    g.bestt.val = TraitsTime;
    g.bestt.d = g.time;
    g.dfs(g.bestt, s, 0);
    if(!identical()) {
        //equal
        printf("Distance = %d; Time = %d:", g.dis[t], g.time[t]);
        printpath(g.bestd.path);
        printf("\n");
    } else {
        printf("Distance = %d:", g.dis[t]);
        printpath(g.bestd.path);
        printf("\n");
        printf("Time = %d:", g.time[t]);
        printpath(g.bestt.path);
        printf("\n");
    }
    return 0;
}