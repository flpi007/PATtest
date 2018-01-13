#include <cstdio>
#include <cstring>
#include <cfloat>
#include <algorithm>
using namespace std;

const int N = 1007;
int n, d;
int idx[N];
double a[N], p[N], r[N];
bool Comp(int a, int b)
{
    return r[a] > r[b];
}
int main()
{
    scanf("%d%d", &n, &d);
    for(int i = 0; i < n; i++) {
        scanf("%lf", &a[i]);
        idx[i] = i;
    }
    for(int i = 0; i < n; i++) {
        scanf("%lf", &p[i]);
        r[i] = p[i] / a[i];
    }
    sort(idx, idx + n, Comp);
    double pro = 0.0;
    for(int i = 0; i < n; i++) {
        int id = idx[i];
        if(a[id] < d) {
            d -= a[id];
            pro += p[id];
        } else {
            pro += p[id] * d / a[id];
            break;
        }
    }
    printf("%.2lf\n", pro);
    return 0;
}