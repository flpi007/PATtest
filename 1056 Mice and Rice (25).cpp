#include <cstdio>
#include <cstring>
// #include <vector>
#include <algorithm>
using namespace std;

const int N = 1000;
int s[N], idx[N], rnk[N], rnkCnt[N];
int np, ng;
int main()
{
    scanf("%d%d", &np, &ng);
    for(int i = 0; i < np; i++) {
        scanf("%d", &s[i]);
    }
    for(int i = 0; i < np; i++) {
        scanf("%d", &idx[i]);
        // printf("%3d ", s[idx[i]]);
    }
    // printf("\n");
    int l = np;
    int level = 0;
    memset(rnkCnt, 0, sizeof(rnkCnt));
    memset(rnk, -1, sizeof(rnk));
    while(l > 1) {
        int maxS[N];
        memset(maxS, 0, sizeof(maxS));
        for(int j = 0; j < l; j++) {
            maxS[j / ng] = max(maxS[j / ng], s[idx[j]]);
        }
        int p = 0;
        for(int j = 0; j < l; j++) {
            if(s[idx[j]] < maxS[j / ng]) {
                rnk[idx[j]] = level;
                rnkCnt[level]++;
                // printf("%3d ", rnk[idx[j]]);
            } else {
                idx[p++] = idx[j];
                // printf("  X ");
            }
        }
        // printf("\n");
        // for(int j = 0; j < l / ng + 1; j++)
        //     printf("%3d ", maxS[j]);
        // printf("\n");
        level++;
        l = p;
    }
    rnkCnt[level] = 1;
    rnk[idx[0]] = level++;
    // printf("%3d\n", rnk[idx[0]]);
    int cnt = 1;
    for(int i = level - 1; i >= 0; i--) {
        int t = rnkCnt[i];
        rnkCnt[i] = cnt;
        cnt += t;
    }
    printf("%d", rnkCnt[rnk[0]]);
    for(int i = 1; i < np; i++)
        printf(" %d", rnkCnt[rnk[i]]);
    return 0;
}