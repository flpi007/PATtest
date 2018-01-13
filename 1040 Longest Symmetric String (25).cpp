#include <cstdio>
#include <cstring>

const int N = 1024;
char s[N];
int n;
bool check(int front, int d)
{
    for(int i = 0; i < d / 2 + 1; i++) {
        if(s[front + i] != s[front + d - i - 1])
            return false;
    }
    return true;
}
int main()
{
    fgets(s, N, stdin);
    n = 0;
    while(s[n])
        n++;
    int ans;
    for(ans = n; ans > 0; ans--) {
        bool b = false;
        // printf("ans:%d\n", ans);
        for(int start = 0; start <= n - ans; start++) {
            if(check(start, ans)) {
                b = true;
                printf("%d\n", ans);
                break;
            }
        }
        if(b) break;
    }
    return 0;
}