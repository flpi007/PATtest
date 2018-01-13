#include <cstdio>
#include <cstring>
#include <cmath>
// #include <vector>
// #include <queue>
// using namespace std;

const int N = 100000;
int n;
int p[N], cnt[N], max, maxCnt;
double price, r;
int Solve(int i)
{
    if(i == -1)
        return -1;
    if(cnt[i] != -1)
        return cnt[i];
    return cnt[i] = Solve(p[i]) + 1;
}
int main()
{
    scanf("%d %lf %lf\n", &n, &price, &r);
    r = 1 + r / 100.0;
    memset(p, -1, sizeof(p));
    memset(cnt, -1, sizeof(cnt));
    for(int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }
    maxCnt = 1;
    max = -1;
    for(int i = 0; i < n; i++) {
        int t = Solve(i);
        if(t > max) {
            max = t;
            maxCnt = 1;
        } else if(t == max) {
            maxCnt++;
        }
    }
    double ans = price * pow(r, double(max));
    printf("%.2lf %d", ans, maxCnt);
    return 0;
}