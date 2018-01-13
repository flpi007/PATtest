#include <cstdio>
#include <cstring>
#include <cctype>

const int N = 100 + 10, M = 20;
struct Real {
    int inte[N], deci[N], mant[2 * N];
    int li = 0, ld = 0, ex;
    Real()
    {
        memset(inte, 0, sizeof(inte));
        memset(deci, 0, sizeof(deci));
    }
    Real(char *s)
    {
        memset(inte, 0, sizeof(inte));
        memset(deci, 0, sizeof(deci));
        int stat = 0;
        while(*s == '0')
            s++;
        for(; *s; s++) {
            if(isdigit(*s)) {
                if(stat == 0) {
                    inte[li++] = *s - '0';
                } else {
                    deci[ld++] = *s - '0';
                }
            } else if(*s == '.') {
                stat = 1;
            }
        }
    }
    void Format()
    {
        memset(mant, 0, sizeof(mant));
        if(li <= 1 && inte[0] == 0) { // 0.0*XXX
            int i = 0;
            while(deci[i] == 0 && i < ld)
                i++;
            if(i < ld) {
                ex = -i;
                for(; i < ld; i++) {
                    mant[ex + i] = deci[i];
                }
            } else {
                ex = 0;
                ld = 0;
            }
        } else { // XX.XXX
            ex = li;
            for(int i = 0; i < li; i++) {
                mant[i] = inte[i];
            }
            for(int i = 0; i < ld; i++) {
                mant[ex + i] = deci[i];
            }
        }
    }
    void Print(int n, const char *s)
    {
        printf("0.");
        for(int i = 0; i < n; i++) {
            printf("%d", mant[i]);
        }
        printf("*10^%d%s", ex, s);
    }
};
int n;
int main()
{
    char s1[N], s2[N];
    scanf("%d%s%s", &n, s1, s2);
    Real a = Real(s1);
    Real b = Real(s2);
    a.Format();
    b.Format();
    int i;
    for(i = 0; i < n; i++) {
        if(a.mant[i] != b.mant[i] || a.ex != b.ex) {
            printf("NO ");
            a.Print(n, " ");
            b.Print(n, "\n");
            return 0;
        }
    }
    if(i == n) {
        printf("YES ");
        a.Print(n, "\n");
    }
    return 0;
}