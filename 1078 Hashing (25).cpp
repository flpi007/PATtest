#include <cstdio>
#include <cstring>

const int M = 10020;
int m, n, u;
int vis[M], table[M], num[M];
int Hash(int k)
{
    int t;
    for(int i = 0; i < u; i++) {
        t = (k + i * i) % u;
        // printf("k:%d i:%d table:%d\n", t, i, table[t]);
        if(table[t] == 0)
            return t;
    }
    return -1;
}
int main()
{
    scanf("%d%d", &m, &n);
    memset(vis, 0, sizeof(vis));
    vis[0] = 1; vis[1] = 1;
    u = 2;
    while(u < M) {
        for(int i = u + u; i < M; i += u)
            vis[i] = 1;
        u++;
        while(vis[u] && u < M)
            u++;
    }
    u = m;
    while(vis[u])
        u++;

    // printf("m:%d\n", u);
    long a;
    memset(table, 0, sizeof(table));
    for(int i = 0; i < n; i++) {
        a = 0;
        scanf("%d", &a);
        // printf("a:%d i:%d\n", a, i);
        a = a % u;
        int t = Hash(a);
        if(t >= 0) {
            table[t] = 1;
            num[i] = t;
        } else {
            num[i] = -1;
        }
    }
    printf("%d", num[0]);
    for(int i = 1; i < n; i++) {
        if(num[i] != -1)
            printf(" %d", num[i]);
        else
            printf(" -");
    }
    return 0;
}