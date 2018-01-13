#include <cstdio>
#include <cstring>
#include <cmath>

const int N = 400;
int n, k, p, l;
int ep[N], ni[N], ans[N];
bool better(int *a, int *b)
{
    int suma = 0, sumb = 0;
    for(int i = 0; i < k; i++) {
        suma += a[i];
        sumb += b[i];
    }
    if(suma > sumb) {
        return true;
    } else if(suma == sumb) {
        for(int i = 0; i < k; i++) {
            if(a[i] > b[i]) {
                return true;
            } else if(a[i] < b[i]) {
                return false;
            }
        }
        return false;
    } else {
        return false;
    }
}
bool dfs(int x, int sum, int d)
{
    if(d == k) {
        if(sum == n && better(ni, ans)) {
            memcpy(ans, ni, sizeof(ans));
            return true;
        }else{
            return false;
        }
    }
    bool valid = false;
    for(int i=x; i>0; i--){
        ni[d] = i;
        if(sum + ep[i] <= n && dfs(i, sum + ep[i], d+1)){
            valid = true;
        }
    }
    return valid;
}
int main()
{
    memset(ep, -1, sizeof(ep));
    scanf("%d%d%d", &n, &k, &p);
    for(l = 0; l < N && pow(l, p) <= n; l++) {
        ep[l] = pow(l, p);
    }
    if(dfs(l - 1, 0, 0)){
        printf("%d =", n);
        for(int i=0;i<k;i++){
            if(i){
                printf(" +");
            }
            printf(" %d^%d", ans[i], p);
        }
        printf("\n");
    }else{
        printf("Impossible\n");
    }
    return 0;
}