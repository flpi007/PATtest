#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int N = 1000, M = 20, Maxn = N + M;
const int INF = 1000000000;
struct Edge {
    int from, to, dis;
    Edge(int f, int t, int d): from(f), to(t), dis(d) {}
};
struct MD {
    int n, m;
    vector<Edge> edges;
    vector<int> G[Maxn];
    int d[Maxn], inq[Maxn];
    void Init(int nn)
    {
        n = nn;
        for(int i = 0; i < Maxn; i++)
            G[i].clear();
        edges.clear();
    }
    void AddEdge(int f, int t, int d)
    {
        edges.push_back(Edge(f, t, d));
        edges.push_back(Edge(t, f, d));
        m = edges.size();
        G[f].push_back(m - 2);
        G[t].push_back(m - 1);
    }
    void BellmanFord(int s)
    {
        memset(inq, 0, sizeof(inq));
        for(int i = 0; i < Maxn; i++)
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
    }
};
int n, m, k, ds;
float sum[M];
MD g;
int read(char *s)
{
    int x = -1;
    if(s[0] == 'G') {
        sscanf(s + 1, "%d", &x);
        x += (n - 1); //n ~ (n+m-1)
    } else {
        sscanf(s, "%d", &x);
        x--; //0 ~ (n-1)
    }
    return x;
}
int main()
{
    scanf("%d %d %d %d\n", &n, &m, &k, &ds);
    g.Init(n + m); //clear maxium
    memset(sum, 0, sizeof(sum));
    for(int i = 0; i < k; i++) {
        char s1[16], s2[16];
        int u, v, d;
        scanf("%s %s %d\n", s1, s2, &d);
        u = read(s1);
        v = read(s2);
        g.AddEdge(u, v, d);
    }
    int bestDis = -1, besti = -1;
    float bestSum = float(INF);
    for(int i = 0; i < m; i++) {
        g.BellmanFord(n + i);
        int t = INF;
        int invalid = 0;
        for(int j = 0; j < n; j++) {
            if(g.d[j] > ds || g.d[j]<bestDis) {
                invalid = 1;
                break;
            } else {
                sum[i] += g.d[j];
            };
            t = min(t, g.d[j]);
        }
        if(invalid)
            continue;
        if(t > bestDis) {
            bestDis = t;
            besti = i;
            bestSum = sum[i];
        } else if(t == bestDis && sum[i] < bestSum) {
            besti = i;
            bestSum = sum[i];
        };
    }
    if(besti == -1)
        printf("No Solution\n");
    else {
        printf("G%d\n", besti + 1);
        float dis = float(bestDis);
        float ave = sum[besti] / n; //accurate up
        printf("%.1f %.1f\n", dis, ave);
    }
    return 0;
}