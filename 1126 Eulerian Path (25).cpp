#include <iostream>
#include <algorithm>
using namespace std;

const int N = 507;
int n, m;
int cnt[N], p[N];
int findP(int u)
{
    if(p[u] == 0 || p[u] == u) {
        return p[u];
    } else {
        return p[u] = findP(p[u]);
    }
}
int main()
{
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        cnt[a]++;
        cnt[b]++;
        if(findP(a) == 0) {
            p[a] = a;
        }
        if(p[b] == 0) {
            p[b] = p[a];
        } else {
            p[findP(b)] = p[a];
        }
    }
    int odd = 0, connet = 1;
    for(int i = 1; i <= n; i++) {
        if(cnt[i] % 2 == 1) {
            odd++;
        }
        if(findP(i) != findP(1)) {
            connet = 0;
        }
    }
    for(int i = 0; i < n; i++) {
        if(i)
            printf(" ");
        printf("%d", cnt[i + 1]);
    }
    printf("\n");
    if(!connet || (odd != 0 && odd != 2)) {
        printf("Non-Eulerian\n");
    } else if(odd == 2) {
        printf("Semi-Eulerian\n");
    } else if(odd == 0) {
        printf("Eulerian\n");
    }
    return 0;
}