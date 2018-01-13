#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int N = 1001, M = 101;
const int INF = 1000000000;
int n, l, k;
int g[N][N], d[N][N], a[N][N];
int q[N], cnt[N];
void MinD(int s)
{
    for(int i = 0; i < n; i++)
        d[s][i] = -1;
    d[s][s] = 0;
    queue<int> q;
    q.push(s);
    int inq[N];
    memset(inq, 0, sizeof(inq));
    inq[s] = 1;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        inq[s] = 0;
        if(d[s][u] > l) continue;
        if(d[s][u] == -1) continue;
        for(int i = 0; i < n; i++) {
            int t = g[u][i];
            if(g[u][i] == -1) t = d[u][i];
            if(t == -1) continue;
            if((d[s][i] > d[s][u] + t || d[s][i] == -1)) { // && d[s][u]+d[u][i]<=l){
                d[s][i] = d[s][u] + t;
                if(!inq[i] && d[s][i] <= l) {
                    q.push(i);
                }
            }
        }
    }
}
void printD()
{
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            printf("%2d ", d[i][j]);
        printf("\n");
    }
}
int main()
{
    memset(g, -1, sizeof(g));
    memset(d, -1, sizeof(d));
    scanf("%d%d", &n, &l);
    for(int i = 0; i < n; i++) {
        int v, m;
        scanf("%d", &m);
        for(int j = 0; j < m; j++) {
            scanf("%d", &v);
            g[v - 1][i] = 1; //renumber 1->N to 0->N-1
        }
        g[i][i] = 0;
    }
    // printD();
    scanf("%d", &k);
    for(int i = 0; i < k; i++) {
        scanf("%d", &q[i]);
        q[i]--;
    }
    for(int i = 0; i < k; i++) {
        int cnt = 0;
        int u = q[i];
        MinD(u);
        for(int j = 0; j < n; j++)
            if(d[u][j] <= l && d[u][j] != -1 && u != j)
                cnt++;
        printf("%d\n", cnt);
    }
    // printD();
    return 0;
}