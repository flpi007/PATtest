#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1007, M = 256;
char s1[N], s2[N];
int cnt[M];
int main(){
    scanf("%s%s", s1, s2);
    memset(cnt, 0, sizeof(cnt));
    char *s;
    for(s = s1; *s!=0; s++){
        cnt[*s]++;
    }
    for(s = s2; *s!=0; s++){
        cnt[*s]--;
    }
    int sum = 0, miss = 0;
    for(int i=0; i<M; i++){
        if(cnt[i]<0){
            miss += -cnt[i];
        }else{
            sum += cnt[i];
        }
    }
    if(miss){
        printf("No %d", miss);
    }else{
        printf("Yes %d", sum);
    }
    return 0;
}