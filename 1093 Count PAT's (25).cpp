#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100007, M = 1000000007;
const char ds[] = "PAT"; //PAT->012
char str[N];
int cnt[3][N];
int madd(int a, int b){
    return ((a % M) + (b % M)) % M;
}
int main()
{
    memset(cnt, 0, sizeof(cnt));
    scanf("%s", str);
    int l;
    for(l = 0; str[l]; l++) {
        if(str[l] == ds[0]) {
            cnt[0][l] = 1;
        } else if(str[l] == ds[1]) {
            cnt[1][l] = 1;
        } else if(str[l] == ds[2]) {
            cnt[2][l] = 1;
        }
    }
    int sum = 0;
    for(int i=l-1; i>=0; i--){
        cnt[2][i] = madd(cnt[2][i], sum);
        sum = cnt[2][i];
    }
    sum = 0;
    for(int i=l-1; i>=0; i--){
        if(cnt[1][i] == 1){
            cnt[1][i] = madd(cnt[2][i], sum);
        }else{
            cnt[1][i] = sum;
        }
        sum = cnt[1][i];
    }
    sum = 0;
    for(int i=l-1; i>=0; i--){
        if(cnt[0][i] == 1){
            cnt[0][i] = madd(cnt[1][i], sum);
        }else{
            cnt[0][i] = sum;
        }
        sum = cnt[0][i];
    }
    // for(int i=0;i<3;i++){
    //     for(int j=0;j<l;j++){
    //         printf("%d ", cnt[i][j]);
    //     }
    //     printf("\n");
    // }
    printf("%d\n", cnt[0][0]);
    return 0;
}