#include <cstdio>
#include <cstring>
#include <cstdlib>
// #include <vector>
// using namespace std;

const int N = 100002, V = 10002;
int n, r, Rer;
int key[N], next[N];
int vis[V];
int main()
{
    scanf("%d%d", &r, &n);
    for(int i = 0; i < n; i++) {
        int addr, k, nxt;
        scanf("%d%d%d", &addr, &k, &nxt);
        key[addr] = k;
        next[addr] = nxt;
    }

    memset(vis, 0, sizeof(vis));
    Rer = N - 1;
    next[Rer] = -1;
    int i = r, j = Rer, pre = r;
    while(i != -1) {
        // printf("k:%d\n", key[i]);
        if(!vis[abs(key[i])]) {
            vis[abs(key[i])] = 1; //move forward
            pre = i;
        } else {
            next[pre] = next[i]; //remove from list
            next[j] = i; //add to remove list
            j = i;
        }
        i = next[i];
    }
    next[j] = -1;

    i = r;
    // printf("\n");
    while(i != -1) {
        int nxt = next[i];
        if(nxt != -1)
            printf("%.5d %d %.5d\n", i, key[i], next[i]);
        else {
            printf("%.5d %d -1\n", i, key[i]);
        }
        i = nxt;
    }
    j = next[Rer];
    // printf("\n");
    while(j != -1) {
        int nxt = next[j];
        if(nxt != -1)
            printf("%.5d %d %.5d\n", j, key[j], next[j]);
        else {
            printf("%.5d %d -1\n", j, key[j]);
        }
        j = nxt;
    }
    return 0;
}