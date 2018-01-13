#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 512;
const double INF = 3.0E38;
int n;
int idx[N];
double dis, cap, dAvg, dCap;
double p[N], d[N];
double cost[N], gas[N];
bool Comp(int a, int b)
{
    return d[a] < d[b];
}
int main()
{
    scanf("%lf%lf%lf%d", &cap, &dis, &dAvg, &n);
    dCap = dAvg * cap;
    for(int i = 0; i < n; i++) {
        scanf("%lf%lf", &p[i], &d[i]);
        p[i] = p[i] / dAvg; // cost/unit -> cost/dis
        idx[i] = i;
        cost[i] = INF;
        gas[i] = 0;
    }
    d[n] = dis; cost[n] = 0.0; gas[n] = 0; idx[n] = n;
    sort(idx, idx + n + 1, Comp);
    for(int i = n; i > 0; i--) {
        for(int j = i - 1; j >= 0; j--) {
            int idi = idx[i], idj = idx[j];
            double dd;
            if((dd = d[idi] - d[idj]) > dCap)
                break;
            double c = p[idj] * dd + cost[idi];
            if(p[idi] > p[idj])
                c -= min(dCap - dd, gas[idi]) * (p[idi] - p[idj]);
            if(c < cost[idj]) {
                cost[idj] = c;
                gas[idj] = dd + (p[idi] > p[idj] ? min(dCap - dd, gas[idi]) : 0);
                // printf("%d->%d\n", j, i);
            }
        }
    }
    if(cost[idx[0]] < INF) {
        printf("%.2f\n", cost[idx[0]]);
    } else {
        int i = 0;
        double x = 0;
        while(d[idx[i]]<=x && i<n) {
            x = d[idx[i]] + dCap;
            i++;
        }
        printf("The maximum travel distance = %.2f\n", x);
    }
    // printf("dCap:%.1f\n", dCap);
    // for(int i = 0; i <= n; i++) {
    //     int id = idx[i];
    //     printf("%.1f %.1f %.1f\n", d[id], cost[id], gas[id]);
    // }
    return 0;
}