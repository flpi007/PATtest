#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 40000, M = 100, K = 5;
int ge[N], f[N], tar[N][K], idx[N], rnk[N];
int quota[M];
vector<int> rec[M];
int n, m, k;
bool Comp(int a, int b)
{
    if(f[a] > f[b])
        return true;
    else if(f[a] < f[b])
        return false;
    if(ge[a] > ge[b])
        return true;
    return false;
}
int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < m; i++)
        scanf("%d", &quota[i]);
    for(int i = 0; i < n; i++) {
        scanf("%d%d", &ge[i], &f[i]);
        f[i] = (f[i] + ge[i]);
        for(int j = 0; j < k; j++)
            scanf("%d", &tar[i][j]);
        idx[i] = i;
    }
    sort(idx, idx + n, Comp);

    int r = 0;
    rnk[idx[0]] = 0;
    for(int i = 1; i < n; i++) {
        if(Comp(idx[i - 1], idx[i]))
            rnk[idx[i]] = ++r;
        else
            rnk[idx[i]] = r;
    }
    int i = 0;
    r = 0;
    while(i < n) {
        int q[M];
        memcpy(q, quota, sizeof(q));
        while(rnk[idx[i]] == r && i < n) {
            int id = idx[i];
            for(int j = 0; j < k; j++) {
                if(q[tar[id][j]] > 0) {
                    rec[tar[id][j]].push_back(id);
                    quota[tar[id][j]]--;
                    break;
                }
            }
            i++;
        }
        r++;
    }
    for(int i = 0; i < m; i++) {
        sort(rec[i].begin(),rec[i].end());
        if(rec[i].size() > 0)
            printf("%d", rec[i][0]);
        for(int j = 1; j < rec[i].size(); j++)
            printf(" %d", rec[i][j]);
        printf("\n");
    }
    return 0;
}
