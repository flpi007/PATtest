#include <cstdio>
#include <cstring>

const int N = 37;
int n, cnt = 0, nfirst = 0;
int pre[N], post[N];
int v[N], left[N], right[N];
bool unique = true;
int build(int prefront, int postend)
{
    if(prefront > n - 1 || postend <= 0) {
        return -1;
    } else {
        // printf("%d-%d\n", pre[prefront], post[postend - 1]);
        // printf("    %d,%d\n", prefront, postend);
        for(int i = postend; i > 0; i--) {
            if(prefront + 1 < n && post[i - 1] == pre[prefront + 1]) {
                left[prefront] = build(prefront + 1, i);
            }
        }
        for(int j = prefront; j < n; j++) {
            if(postend - 2 >= 0 && pre[j] == post[postend - 2] && \
               j != prefront + 1) {
                right[prefront] = build(j, postend - 1);
            }
        }
        if((right[prefront] == -1) ^ (left[prefront] == -1)) {
            unique = false;
        }
        return prefront;
    }
}
void inorder(int u)
{
    if(u == -1) {
        return;
    } else {
        inorder(left[u]);
        if(nfirst) {
            printf(" ");
        }
        nfirst = 1;
        printf("%d", pre[u]);
        inorder(right[u]);
    }
}
int main()
{
    memset(left, -1, sizeof(left));
    memset(right, -1, sizeof(right));
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int t;
        scanf("%d", &pre[i]);
    }
    for(int i = 0; i < n; i++) {
        int t;
        scanf("%d", &post[i]);
    }
    build(0, n);
    if(unique) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    inorder(0);
    printf("\n");
    return 0;
}