#include <cstdio>
#include <cstring>
#include <cstdlib>

const int N = 30;
int k, n;
int pre[N], lc[N], rc[N];
int val(int x){
    return x != -1 ? pre[x] : -1;
}
int build(int l, int r)
{
    if(l >= r) {
        return -1;
    }
    int k;
    for(k = l; k < r && abs(pre[k]) <= abs(pre[l]); k++); // [l..k..r)
    lc[l] = build(l + 1, k);
    rc[l] = build(k, r);
    // printf("tree %d:%d %d\n", val(l), val(lc[l]), val(rc[l]));
    return l;
}
int check(int x, bool &isBlack)
{
    if(x == -1) {
        isBlack = true;
        return 0;
    }
    bool lb, rb;
    int l = check(lc[x], lb);
    int r = check(rc[x], rb);
    isBlack = pre[x] > 0 ? true : false;
    if(l != r || l == -1 || r == -1 || (!isBlack && (!lb || !rb))) {
        return -1;
    }
    if(isBlack) {
        return l + 1;
    } else {
        return l;
    }
}
int main()
{
    scanf("%d", &k);
    for(int kase = 0; kase < k; kase++) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%d", &pre[i]);
        }
        memset(lc, -1, sizeof(lc));
        memset(rc, -1, sizeof(rc));
        build(0, n);
        bool isBlack;
        int valid = check(0, isBlack);
        if(valid > 0 && isBlack){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
    return 0;
}