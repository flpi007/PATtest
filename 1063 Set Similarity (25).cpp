#include <cstdio>
#include <cstring>
#include <set>
using namespace std;
const int N = 50;

int n, k, m;
set<int> s[N];
void solve(int a, int b)
{
    set<int>::iterator ia, ib;
    int cnt = 0;
    ia = s[a].begin();
    ib = s[b].begin();
    while(1) {
        while(ia != s[a].end() && *ia < *ib)
            ia++;
        while(ib != s[b].end() && *ib < *ia)
            ib++;
        if(ia == s[a].end() || ib == s[b].end())
            break;
        if(*ib == *ia) {
            cnt++;
            ia++;
            ib++;
        }
    }
    int sum = s[a].size() + s[b].size() - cnt;
    printf("%.1f%%\n", double(cnt*100) / sum);
}
int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &m);
        for(int j = 0; j < m; j++) {
            int t;
            scanf("%d", &t);
            s[i].insert(t);
        }
    }
    scanf("%d", &k);
    for(int i = 0; i < k; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        solve(a - 1, b - 1);
    }
    return 0;
}