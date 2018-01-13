#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int L = 60, M = 1286, N = 128;
const int dx[] = {1, -1, 0, 0, 0, 0};
const int dy[] = {0, 0, 1, -1, 0, 0};
const int dz[] = {0, 0, 0, 0, 1, -1};
struct P {
    int x, y, z;
    P(int xx, int yy, int zz): x(xx), y(yy), z(zz) {}
};
int n, m, l, t, cnt;
int g[L][M][N];
int vis[L][M][N];
void Bfs(int a, int b, int c)
{
    int size = 0;
    queue<P> q;
    q.push(P(a, b, c));
    vis[a][b][c] = 1;
    while(!q.empty()) {
        P p = q.front(); q.pop();
        size++;
        int x = p.x, y = p.y, z = p.z;
        // printf("%d %d %d", x,y,z);
        for(int k = 0; k < 6; k++) {
            int u = x + dx[k], v = y + dy[k], w = z + dz[k];
            if(u < 0 || u >= l || v < 0 || v >= m || w < 0 || w >= n)
                continue;
            if(!vis[u][v][w] && g[u][v][w]) {
                q.push(P(u, v, w));
                vis[u][v][w] = 1;
            }
        }
    }
    if(size >= t) cnt+=size;
}
int main()
{
    scanf("%d%d%d%d", &m, &n, &l, &t);
    memset(g, 0, sizeof(g));
    for(int i = 0; i < l; i++) {
        for(int j = 0; j < m; j++) {
            for(int k = 0; k < n; k++) {
                scanf("%d", &g[i][j][k]);
            }
        }
    }
    memset(vis, 0, sizeof(0));
    cnt = 0;
    for(int i = 0; i < l; i++)
        for(int j = 0; j < m; j++)
            for(int k = 0; k < n; k++) {
                if(g[i][j][k] == 0 || vis[i][j][k])
                    continue;
                Bfs(i, j, k);
            }
    printf("%d\n", cnt);
    return 0;
}