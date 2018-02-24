#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

const int N = 30;
int n;
int post[N], in[N], lc[N], rc[N];
int build(int l, int r, int h)
{
    if(l >= r) {
        return -1;
    }
    //inorder [l..i..r)
    //postorder <i - l><r - (i + 1)>h
    for(int i = l; i < r; i++) {
        if(in[i] == post[h]) {
            int t = r - (i + 1);
            lc[h] = build(l, i, h - 1 - t);
            rc[h] = build(i + 1, r, h - 1);
            break;
        }
    }
    return h;
}
int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &post[i]);
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", &in[i]);
    }
    memset(lc, -1, sizeof(lc));
    memset(rc, -1, sizeof(rc));
    build(0, n, n - 1);
    bool first = true;
    queue<int> q;
    q.push(n - 1);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        if(u != -1) {
            if(!first) {
                printf(" ");
            };
            printf("%d", post[u]);
            first = false;
            q.push(lc[u]);
            q.push(rc[u]);
        }
    }
    printf("\n");
    return 0;
}