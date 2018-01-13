#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100000 + 10, M = 1000 + 10;
int n, m;
int cnt[M];
int main()
{
    memset(cnt, 0, sizeof(cnt));
    scanf("%d %d\n", &n, &m);
    for(int i = 0; i < n; i++) {
        int coin;
        scanf("%d", &coin);
        cnt[coin]++;
    }
    for(int i = 0; i < M; i++) {
        int j = m - i;
        if(i != j && cnt[i] && cnt[j] || \
           i == j && cnt[i] >= 2) {
            printf("%d %d\n", i, j);
            return 0;
        }
    }
    printf("No Solution\n");
    return 0;
}t