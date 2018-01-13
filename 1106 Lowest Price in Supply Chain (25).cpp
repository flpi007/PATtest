#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

const int N = 100000, ROOT = 0;
int n, best, bestc;
vector<int> childs[N];
void dfs(int u, int d)
{
    if(childs[u].size() == 0) {
        if(d < best) {
            best = d;
            bestc = 1;
        } else if(d == best) {
            bestc++;
        }
    }else if(d < best){
        for(int i = 0; i < childs[u].size(); i++) {
            dfs(childs[u][i], d + 1);
        }
    }
}
int main()
{
    double p, r;
    scanf("%d %lf %lf", &n, &p, &r);
    for(int i = 0; i < n; i++) {
        int k;
        scanf("%d", &k);
        for(int j = 0; j < k; j++) {
            int id;
            scanf("%d", &id);
            childs[i].push_back(id);
        }
    }
    best = N;
    dfs(ROOT, 0);
    printf("%.4lf %d\n", p * pow(1.0 + r / 100, best),bestc);
    return 0;
}