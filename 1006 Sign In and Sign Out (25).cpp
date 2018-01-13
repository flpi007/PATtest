#include <cstdio>
#include <cstring>

const int N = 20;
int main()
{
    char minN[N], maxN[N], name[N];
    int n, mint = 100000000, maxt = -1;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int hh, mm, ss, it, ot;
        scanf("%s ", name);
        scanf("%d:%d:%d", &hh, &mm, &ss);
        it = hh * 3600 + mm * 60 + ss;
        if(it < mint) {
            strcpy(minN, name);
            mint = it;
        }
        scanf("%d:%d:%d", &hh, &mm, &ss);
        ot = hh * 3600 + mm * 60 + ss;
        if(ot > maxt) {
            strcpy(maxN, name);
            maxt = ot;
        }

    }
    printf("%s %s\n", minN, maxN);
    return 0;
}