#include <cstdio>
#include <cstring>

const int N = 54, M = 13;
const char P[] = {'S', 'H', 'C', 'D', 'J'};
int k;
int idx[2][N], t[N];
void Print(int x)
{
    int i = x / M, j = x % M + 1;
    printf("%c%d", P[i], j);
}
int main()
{
    scanf("%d", &k);
    for(int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        t[i] = x - 1;
        idx[0][i] = i;
    }
    int a = 0, b = 1;
    while(k--) {
        for(int i = 0; i < N; i++) {
            idx[b][t[i]] = idx[a][i];
        }
        a ^= 1;
        b ^= 1;
    }
    Print(idx[a][0]);
    for(int i = 1; i < N; i++) {
        printf(" ");
        Print(idx[a][i]);
    }
    printf("\n");
    return 0;
}