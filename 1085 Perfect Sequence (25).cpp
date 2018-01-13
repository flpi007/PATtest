#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
const int N = 100007;
int n;
ll p;
ll a[N];
int main()
{
    scanf("%d%lld", &n, &p);
    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    sort(a, a + n);
    int j = 0, ans = 0;
    for(int i = 0; i < n; i++) {
        ll upper = a[i] * p;
        for(; j < n && a[j] <= upper; j++);
        ans = max(ans, j - i);
    }
    printf("%d\n", ans);
    return 0;
}