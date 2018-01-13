#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

const int N = 100003, ROOT = 0;
int n;
double p, r, total;
vector<int> ch[N];
int amount[N];
int power[N];
void Dfs(int u, int d)
{
    if(ch[u].size() == 0) {
        power[d] += amount[u];
        return;
    }
    for(int i = 0; i < ch[u].size(); i++) {
        Dfs(ch[u][i], d + 1);
    }
}
int main()
{
    scanf("%d %lf %lf\n", &n, &p, &r);
    r = 1 + r / 100.0;
    for(int i = 0; i < n; i++) {
        int k, t;
        scanf("%d", &k);
        ch[i].clear();
        if(k == 0) {
            scanf("%d", &t);
            amount[i] = t;
        }else{
            for(int j = 0; j < k; j++) {
                scanf("%d", &t);
                ch[i].push_back(t);
            }
        }
    }
    memset(power, 0, sizeof(power));
    Dfs(ROOT, 0);
    total = 0;
    for(int i = 0; i < n; i++) {
        if(power[i] > 0)
            total += power[i] * pow(r, i);
    }
    total = p * total;
    printf("%.1lf\n", total);
    return 0;
}