#include <cstdio>
#include <vector>
#include <set>
using namespace std;

const int N = 1007, M = 37;
const char chs[M] = {
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '_',
};
int k;
set<char> stuck;
vector<char> seq;
int check(int c, char *s)
{
    char *str;
    for(str = s; *str;) {
        if(*str == c) {
            for(int i = 0; i < k; i++) {
                if(*str != c) {
                    return 0;
                }
                str++;
            }
        } else {
            str++;
        }
    }
    return 1;
}
int main()
{
    char str[N];
    scanf("%d\n", &k);
    scanf("%s", str);
    for(int i = 0; i < M; i++) {
        if(check(chs[i], str)) {
            stuck.insert(chs[i]);
        }
    }
    char *s;
    set<char> found;
    for(s = str; *s; s++) {
        if(stuck.find(*s) != stuck.end() && found.find(*s) == found.end()) {
            seq.push_back(*s);
            found.insert(*s);
        }
    }
    for(int i = 0; i < seq.size(); i++) {
        printf("%c", seq[i]);
    }
    printf("\n");
    for(s = str; *s; ) {
        printf("%c", *s);
        if(stuck.find(*s) != stuck.end()) {
            s += k;
        } else {
            s++;
        }
    }
    printf("\n");
    return 0;
}