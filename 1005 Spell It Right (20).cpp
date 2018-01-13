#include <cstdio>
#include <cctype>
#include <cstring>

const int N = 105;
const char *numb[] = {
    "zero",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine",
};

int n, sum;
int main()
{
    char str[N], *s;
    scanf("%s", str);
    sum = 0;
    for(s = str; *s; s++) {
        if(isdigit(*s)) {
            sum += *s - '0';
        }
    }
    char out[N];
    sprintf(out, "%d", sum);
    for(s = out; *s; s++) {
        if(s != out) {
            printf(" ");
        }
        printf("%s", numb[*s - '0']);
    }
    printf("\n");
    return 0;
}