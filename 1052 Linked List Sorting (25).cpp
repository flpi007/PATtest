#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100001;
int n;
int key[N], nxt[N], vis[N], idx[N];
bool Comp(int a, int b)
{
    return key[a] < key[b];
}
int main()
{
    int head;
    scanf("%d%d\n", &n, &head);
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i < n; i++) {
        int addr;
        scanf("%d", &addr);
        scanf("%d%d", &key[addr], &nxt[addr]);
        vis[addr] = 1;
    }
    int cnt = 0;
    memset(idx, -1, sizeof(idx));
    while(head != -1 && vis[head]) {
        idx[cnt++] = head;
        head = nxt[head];
    }
    sort(idx, idx + cnt, Comp);
    if(cnt <= 0){
        printf("0 -1\n");
    }else{
        printf("%d %05d\n", cnt, idx[0]);
        for(int i=0;i<cnt-1;i++){
            printf("%05d %d %05d\n", idx[i], key[idx[i]], idx[i+1]);
        }
        printf("%05d %d -1\n", idx[cnt-1], key[idx[cnt-1]]);
    }
    return 0;
}