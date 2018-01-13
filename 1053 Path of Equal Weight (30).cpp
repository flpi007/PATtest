#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 100, M = 100, ROOT = 0;
int n, m, s;
int w[N], path[N];
vector<int> ch[N];
void dfs(int p, int x, int d)
{
    if(ch[p].size() == 0) { //leaf
        if(x == w[p]) {
            path[d++] = w[p];
            printf("%d", path[0]);
            for(int i = 1; i < d; i++)
                printf(" %d", path[i]);
            printf("\n");
        }
        return;
    }
    if(x < w[p])
        return;
    x -= w[p];
    path[d++] = w[p];
    for(int i = 0; i < ch[p].size(); i++) {
        dfs(ch[p][i], x, d);
    }
}
bool Comp(int a,int b){
    return w[a]>w[b];
}
int main()
{
    scanf("%d%d%d", &n, &m, &s);
    for(int i = 0; i < n; i++)
        scanf("%d", &w[i]);
    for(int i = 0; i < m; i++) {
        int id, k, t;
        scanf("%d%d", &id, &k);
        for(int j = 0; j < k; j++) {
            scanf("%d", &t);
            ch[id].push_back(t);
        }
        sort(ch[id].begin(), ch[id].end(), Comp);
    }
    dfs(0, s, 0);
    return 0;
}