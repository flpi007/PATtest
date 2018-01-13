#include <cstdio>
#include <cstring>
#include <cctype>

const int M = 32;
const char* low[13] = {
    "tret",
    "jan",
    "feb",
    "mar",
    "apr",
    "may",
    "jun",
    "jly",
    "aug",
    "sep",
    "oct",
    "nov",
    "dec",
};
const char* high[13] = {
    "null",
    "tam",
    "hel",
    "maa",
    "huh",
    "tou",
    "kes",
    "hei",
    "elo",
    "syy",
    "lok",
    "mer",
    "jou",
};
int n;
void toEarth(char *s){
    int ans = 0;
    char a[M], b[M];
    int t = sscanf(s, "%s %s", a, b);
    for(int i=0; i<13; i++){
        if(strcmp(a, low[i]) == 0){
            ans += i;
            break;
        }else if(strcmp(a, high[i]) == 0){
            ans += 13 * i;
            break;
        }
    }
    if(t == 2){
        for(int i=0; i<13; i++){
            if(strcmp(b, low[i]) == 0){
                ans += i;
                break;
            }else if(strcmp(b, high[i]) == 0){
                ans += 13 * i;
                break;
            }
        }
    }
    printf("%d\n", ans);
}
void toMars(char *s){
    int x;
    sscanf(s, "%d", &x);
    int second = x / 13;
    int first = x % 13;
    if(second == 0){
        printf("%s\n", low[first]);
    }else if(second > 0 && first > 0){
        printf("%s ", high[second]);
        printf("%s\n", low[first]);
    }else if(second > 0 && first == 0){
        printf("%s\n", high[second]);
    }
}
int main(){
    scanf("%d\n", &n);
    for(int i=0; i<n; i++){
        char str[M];
        fgets(str, M, stdin);
        if(isalpha(*str)){
            toEarth(str);
        }else {
            toMars(str);
        }
    }
    return 0;
}   