#include <cstdio>
#include <cstring>

const int N = 100010;
int nxt[N], vis[N];
int main()
{
    int a, b, n;
    scanf("%d%d%d\n", &a, &b, &n);
    memset(vis, 0, sizeof(vis));
    memset(nxt, -1, sizeof(nxt));
    for(int i = 0; i < n; i++) {
        int addr, next;
        char c;
        scanf("%d %c %d\n", &addr, &c, &next);
        nxt[addr] = next;
    }
    while(nxt[a] != -1){
        vis[a] = 1;
        a = nxt[a];
    }
    while(nxt[b] != -1 && !vis[b]){
        b = nxt[b];
    }
    if(vis[b]){
        printf("%05d\n", b);
    }else{
        printf("-1\n");
    }
    return 0;
}