#include <cstdio>
#include <cstring>

const int N = 100;
int main()
{
    char s[N];
    scanf("%s", s);
    int n;
    for(n = 0; s[n] != 0; n++);
    // n2 = n + 2 - 2 * n1
    // n1 <= n2
    int n1, n2;
    for(n1 = (n + 2) / 3; (n2 = n + 2 - 2 * n1) < 3 && n1 > 0; n1--);
    for(int i = 0; i < n1 - 1; i++) {
        printf("%c", s[i]);
        for(int j = 1; j < n2 - 1; j++)
            printf(" ");
        printf("%c\n", s[n - i - 1]);
    }
    for(int i = 0; i < n2; i++)
        printf("%c", s[n1 - 1 + i]);
    return 0;
}