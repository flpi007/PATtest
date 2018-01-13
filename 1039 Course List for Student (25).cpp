#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

vector <int> vt[300000];
int hassh(char *s)
{
    return 26 * 26 * 10 * (s[0] - 'A') + 26 * 10 * (s[1] - 'A') + 10 * (s[2] - 'A') + s[3] - '0';
}
int n, k;
char s[10];
int main()
{
    while(scanf("%d%d", &n, &k) != EOF) {
        for(int i = 0; i < k; i++) {
            int index, b;
            scanf("%d%d", &index, &b);
            for(int j = 0; j < b; j++) {
                scanf("%s", s);
                int t = hassh(s);
                vt[t].push_back(index);
            }
        }
        for(int i = 0; i < n; i++) {
            scanf("%s", s);
            int t = hassh(s);
            printf("%s", s);
            sort(vt[t].begin(), vt[t].end());
            printf(" %d", vt[t].size());
            for(int j = 0; j < vt[t].size(); j++)
                printf(" %d", vt[t][j]);
            puts("");
        }
    }
    return 0;
}