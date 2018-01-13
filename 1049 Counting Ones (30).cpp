#include <cstdio>
#include <cstring>

const int N = 20;
const int s[] = {
    1,
    10,
    100,
    1000,
    10000,
    100000,
    1000000,
    10000000,
    100000000,
    1000000000,
};
int n, a[N], front[N], end[N];
int main()
{
    memset(a, 0, sizeof(a));
    scanf("%d", &n);
    int k = 0;
    for(front[k] = n; front[k] != 0; k++) {
        end[k] = n - front[k] * s[k];
        a[k] = front[k] % 10;
        front[k + 1] = front[k] / 10;
    }
    // printf("%d\n", k);
    // for(int i = 0; i < k + 1; i++) {
    //     printf("%d %d %d\n", front[i], end[i], a[i]);
    // }
    int ans = 0;
    ans += a[k - 1] == 1 ? end[k - 1] + 1 : s[k-1];
    for(int i = k - 2; i > 0; i--) {
        int x = front[i + 1];
        ans += x * s[i]; //0~x-1
        ans += a[i] == 1 ? end[i] + 1 : (a[i] > 1) * s[i];
    }
    if(k - 1 != 0) {
        int x = front[1];
        ans += x;
        ans += a[0] > 0 ? 1 : 0;
    }
    printf("%d\n", ans);
    return 0;
}