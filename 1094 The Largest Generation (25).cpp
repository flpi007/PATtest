#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int N = 100, ROOT = 1;
int n, m, maxCnt, maxd;
vector<int> ch[N];
int cnt[N];
void Dfs(int from, int d)
{
    cnt[d]++;
    if(cnt[d] > maxCnt) {
        maxCnt = cnt[d];
        maxd = d;
    }
    for(int i = 0; i < ch[from].size(); i++) {
        Dfs(ch[from][i], d + 1);
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    // for(int i=0;i<n;i++)
    //     ch[i].clear();
    memset(cnt, 0, sizeof(cnt));
    for(int i = 0; i < m; i++) {
        int u, k, v;
        scanf("%d%d", &u, &k);
        for(int j = 0; j < k; j++) {
            scanf("%d", &v);
            ch[u].push_back(v);
        }
    }
    maxCnt = 0;
    maxd = -1;
    Dfs(ROOT, 0);
    printf("%d %d\n", maxCnt, maxd + 1);
    return 0;
}