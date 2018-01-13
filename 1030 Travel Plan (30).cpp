#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
using namespace std;

const int N = 577, INF = 1000000000;
int n, m, s, des;
int d[N][N], c[N][N], l[N];
int mincost;
stack<int> path;
bool dfs(int u, int cost)
{
    if(u == des) {
        if(cost < mincost) {
            mincost = cost;
            while(!path.empty()) {
                path.pop();
            }
            path.push(u);
            return true;
        } else {
            return false;
        }
    }
    bool better = false;
    for(int i = 0; i < n; i++) {
        if(d[u][i] != -1 && l[i] == l[u] + d[u][i] && dfs(i, cost + c[u][i])) {
            path.push(u);
            better = true;
        }
    }
    return better;
}
void minDis()
{
    for(int i = 0; i < n; i++) {
        l[i] = INF;
    }
    l[s] = 0;
    int inq[N];
    memset(inq, 0, sizeof(inq));
    inq[s] = 1;
    queue<int> q;
    q.push(s);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        inq[u] = 0;
        for(int i = 0; i < n; i++) {
            if(d[u][i] != -1 && l[u] + d[u][i] < l[i]) {
                l[i] = l[u] + d[u][i];
                if(!inq[i]) {
                    q.push(i);
                    inq[i] = 1;
                }
            }
        }
    }
}
int main()
{
    memset(d, -1, sizeof(d));
    scanf("%d%d%d%d", &n, &m, &s, &des);
    for(int i = 0; i < m; i++) {
        int c1, c2, dis, cost;
        scanf("%d%d%d%d", &c1, &c2, &dis, &cost);
        if(d[c1][c2] == -1 || (d[c1][c2] != -1 && dis < d[c1][c2])) {
            d[c1][c2] = dis;
            d[c2][c1] = dis;
            c[c1][c2] = cost;
            c[c2][c1] = cost;
        }
    }
    minDis();
    mincost = INF;
    dfs(s, 0);
    while(!path.empty()) {
        int u = path.top(); path.pop();
        printf("%d ", u);
    }
    printf("%d %d\n", l[des], mincost);
    return 0;
}