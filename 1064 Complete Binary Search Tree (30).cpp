#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int N = 1010;

int n, cnt;
int a[N], val[N];
void Place(int pos)
{
    if(cnt >= n || pos >= n) return;
    Place(pos * 2 + 1);
    val[pos] = cnt++;
    Place(pos * 2 + 2);
}
int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    cnt = 0;
    Place(0);

    printf("%d", a[val[0]]);
    for(int i=1;i<n;i++)
        printf(" %d", a[val[i]]);
    return 0;
}