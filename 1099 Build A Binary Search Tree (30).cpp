#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int N = 101, ROOT = 0;
int n;
int a[N], lc[N], rc[N], idx[N];
int cnt;
void InOrder(int i)
{
    if(i == -1) {
        return;
    }
    InOrder(lc[i]);
    idx[i] = cnt++;
    InOrder(rc[i]);
}
int main()
{
    memset(lc, -1, sizeof(lc));
    memset(rc, -1, sizeof(rc));
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        lc[i] = l;
        rc[i] = r;
    }
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    cnt = 0;
    InOrder(ROOT);

    sort(a, a + n);
    int nfirst = 0;
    queue<int> q;
    q.push(ROOT);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        if(u != -1) {
            if(nfirst) {
                printf(" ");
            }
            printf("%d", a[idx[u]]);
            q.push(lc[u]);
            q.push(rc[u]);
        }
        nfirst = 1;
    }
    return 0;
}