#include <cstdio>
#include <cstring>

const int N = 100, L = 256 + 10;
int n;
char s[L];
char l[N][L];
int main()
{
    scanf("%d\n", &n);
    int maxlen = 0;
    for(int i = 0; i < n; i++) {
        scanf("%s", s);
        int t;
        for(t = 0; t < L && s[t] != '\n' && s[t]; t++); //get length t
        if(i == 0) {
            maxlen = t;
        }
        for(int j = 0; j < t && j < maxlen; j++) {
            l[i][j] = s[t - j - 1];
            if(i > 0 && l[i][j] != l[i - 1][j]) {
                maxlen = j;
                break;
            }
        }
        // printf("%s %d\n", l[i], t);
    }
    if(maxlen == 0) {
        printf("nai\n");
        return 0;
    }
    for(int i = maxlen - 1; i >= 0; i--) {
        printf("%c", l[0][i]);
    }
    return 0;
}