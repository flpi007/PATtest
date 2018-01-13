#include <cstdio>
#include <cstring>
#include <cctype>

const int N = 10007;
struct Real {
    int e, i;
    int f[N], lf;
    Real() {}
    Real(char *s)
    {
        memset(f, 0, sizeof(f));
        sscanf(s, "%d", &i);
        s += 3;
        lf = 0;
        f[lf++] = i > 0 ? i : -i;
        for(; isdigit(*s); s++) {
            f[lf++] = *s - '0';
        }
        s += 1;
        sscanf(s, "%d", &e);
        e++;
        //0.xxxxExx
    }
    void print()
    {
        if(i < 0) {
            printf("-");
        }
        if(e <= 0) {
            printf("0.");
            for(;e<0;e++){
                printf("0");
            }
            for(int j = 0; j < lf; j++) {
                printf("%d", f[j]);
            }
        } else {
            for(int j = 0; j < lf || j < e; j++) {
                if(e == j) {
                    printf(".");
                }
                printf("%d", f[j]);
            }
        }
        printf("\n");
    }
};
int main()
{
    char str[N];
    scanf("%s", str);
    Real r(str);
    r.print();
    return 0;
}