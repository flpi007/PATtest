#include <cstdio>
#include <cstring>

const int N = 20;
char s[N], s1[N], s2[N];
int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%s", s);
        int slen = strlen(s) / 2;
        for(int j=0; j < slen; j++){
            s1[j] = s[j];
            s2[j] = s[j + slen];
        }
        s1[slen] = s2[slen] = 0;
        long long a, b, c;
        sscanf(s, "%lld", &c);
        sscanf(s1, "%lld", &a);
        sscanf(s2, "%lld", &b);
        // printf("%lld %lld\n", a, b);
        if(a != 0 && b != 0 && c % a == 0 && (c / a) % b == 0){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
}