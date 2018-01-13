#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 10000 + 5, M = 100 + 5;
int n, m;
int c[N], vis[N];
int fail[N][M];
int dfs(int i, int x)
{
    if(x == 0) {
        return 1;
    } else if(x < c[i] || fail[i][x] || i >= n) {
        fail[i][x] = 1;
        return 0;
    } else {
        if(dfs(i + 1, x - c[i])) {
            vis[i] = 1;
            return 1;
        } else {
            fail[i + 1][x - c[i]] = 1;
        }
        if(dfs(i + 1, x)) {
            vis[i] = 0;
            return 1;
        } else {
            fail[i][x] = 1;
            return 0;
        }
    }
}
int main()
{
    scanf("%d %d\n", &n, &m);
    for(int i = 0; i < n; i++)
        scanf("%d", &c[i]);
    sort(c, c + n);
    memset(vis, 0, sizeof(vis));
    memset(fail, 0, sizeof(fail));
    int b = dfs(0, m);
    if(!b)
        printf("No Solution");
    else {
        int first = 1;
        for(int i = 0; i < n; i++) {
            if(vis[i]) {
                if(!first) {
                    printf(" ");
                }
                printf("%d", c[i]);
                first = 0;
            }
        }
    }
    printf("\n");
    return 0;
}