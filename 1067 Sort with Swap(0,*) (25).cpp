#include <cstdio>
#include <cstring>

const int N = 100000;

int vis[N], a[N];
int n, edgeCnt = 0, loopCnt = 0, hasZero = 0;
void findloop(int i)
{
    loopCnt++;
    while(a[i] != i && !vis[i]) {
        if(a[i] == 0) hasZero = 1;
        edgeCnt++;
        vis[i] = 1;
        i = a[i];
    }
}
int main()
{
    scanf("%d", &n);
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for(int i = 0; i < n; i++) {
        if(a[i] != i && !vis[i])
            findloop(i);
    }
    printf("%d\n", edgeCnt + loopCnt - 2 * hasZero);
    return 0;
}