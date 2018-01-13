#include <cstdio>
#include <cstring>
#include <set>
using namespace std;

const int N = 10002;
char s1[N], s2[N];
set<char> s;
int main()
{
    fgets(s1, N, stdin);
    fgets(s2, N, stdin);
    for(char *i = s2; *i; i++) {
        s.insert(*i);
    }
    for(char *i = s1; *i; i++) {
        if(s.find(*i) == s.end())
            printf("%c", *i);
    }
    return 0;
}