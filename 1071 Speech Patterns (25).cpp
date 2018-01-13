#include <cstdio>
#include <cstring>
#include <cctype>
#include <vector>
#include <string>
using namespace std;

const int N = 1048583, MOD = 1048583;
string hash[N];
int cnt[N];
int getLex(string &str)
{
    char s[M], c;
    int i = 0, start = 0;
    while((c = getchar()) != '\n' && i < N) {
        // printf("%c", tolower(c));
        if(isalpha(c) || isdigit(c)) {
            *s = c;
            start = 1;
        } else if(start) {
            str = string(s);
            return 1;
        }
    }
    return 0;
}
int HashHit(string &s){
    int k = ELFhash(s);
    int t = k % MOD;
    while(hash[t] != )
}
int main()
{
    int ans = 0;
    string ansStr;
    string str;
    while(getLex(str)){
        int t = HashHit(str);
        if(ans < t || (ans == t && str < ansStr)){
            ans = t;
            ansStr = str;
        }
    }
    printf("%d %s\n", ans, ansStr.c_str());
    return 0;
}