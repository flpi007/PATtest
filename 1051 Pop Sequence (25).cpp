#include <cstdio>
#include <stack>
using namespace std;

const int N = 1000, M = 1000, K = 1000;
int n, m, k;
int s[N];
int main()
{
    scanf("%d%d%d", &m, &n, &k);
    for(int i = 0; i < k; i++) {
        int sp = -1, cnt = 1, b = 1;
        for(int j = 0; j < n; j++) {
            int t;
            scanf("%d", &t);
            if(!b) continue;
            while(sp < m && (sp < 0 || s[sp] != t))
                s[++sp] = cnt++; //push
            if(sp >= 0 && sp < m && s[sp] == t)
                sp--; //pop
            else {
                b = 0;
                printf("NO\n");
            }
        }
        if(b && sp == -1)
            printf("YES\n");
    }
    return 0;
}