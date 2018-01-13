#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int  N = 201, M = 201, L = 10001;
int n, m, l;
int order[M];
int s[L];
int d[L][M];
int dfs(int iS, int iOrder)
{
    if(iOrder >= m || iS >= l)
        return 0;
    if(d[iS][iOrder] != -1)
        return d[iS][iOrder];
    int t;
    //remove stripe
    t = dfs(iS + 1, iOrder);
    //save stripe
    for(int j = iOrder; j < m; j++)
        if(order[j] == s[iS]) {
            return d[iS][iOrder] = max(1 + dfs(iS + 1, j), t);
        }
    return d[iS][iOrder] = t;
}
int main()
{
    memset(d, -1, sizeof(d));
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++)
        scanf("%d", &order[i]);
    scanf("%d", &l);
    for(int i = 0; i < l; i++)
        scanf("%d", &s[i]);
    int ans = dfs(0, 0);
    printf("%d\n", ans);
    return 0;
}