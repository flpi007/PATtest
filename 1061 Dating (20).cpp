#include <cstdio>
#include <cctype>
#include <cstring>

const char *DAY[7] = {
    "MON",
    "TUE",
    "WED",
    "THU",
    "FRI",
    "SAT",
    "SUN",
};
const int N = 60 + 10;
char s[4][N];
int main()
{
    scanf("%s%s%s%s", s[0], s[1], s[2], s[3]);
    int day, hh, mm, i;
    for(i = 0; s[0][i] && s[1][i]; i++) {
        if(isupper(s[0][i]) && s[0][i] == s[1][i] && s[0][i] <= 'G') {
            day = s[0][i] - 'A';
            break;
        }
    }
    for(i++; s[0][i] && s[1][i]; i++) {
        if(s[0][i] == s[1][i]) {
            if(isupper(s[0][i]) && s[0][i] <= 'N'){
                hh = s[0][i] - 'A' + 10;
                break;
            }else if(isdigit(s[0][i])){
                hh = s[0][i] - '0';
                break;
            }
        }
    }
    for(i = 0; s[2][i] && s[3][i]; i++) {
        if(isalpha(s[2][i]) && \
            s[2][i] == s[3][i]) {
            mm = i;
            break;
        }
    }
    printf("%s %02d:%02d\n", DAY[day], hh, mm);
    return 0;
}