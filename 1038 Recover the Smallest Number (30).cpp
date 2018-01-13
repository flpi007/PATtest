#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 10000, M = 9;
const char maxS[M] = {'9' + 1, 0};
struct Seg {
    char s[M];
    int len;
    Seg(): len(0) {}
    Seg(const char *str)
    {
        len = 0;
        while(*str != 0)
            s[len++] = *(str++);
    }
    void Print(bool first)
    {
        if(!first)
            printf("%s", s);
        else {
            char *ss = s;
            while(*ss == '0')
                ss++;
            printf("%s", ss);
        }
    }
    bool Lower(const Seg &rhs, int x) const
    {
        for(int i = 0; i < x; i++) {
            if(s[i] < rhs.s[i])
                return true;
            else if(s[i] > rhs.s[i])
                return false;
        }
        return false;
    }
};
int n;
Seg seg[N];
int vis[N], lenCnt[M], x;
bool Comp(int a, int b)
{
    return seg[a].Lower(seg[b], x);
}
int main()
{
    memset(lenCnt, 0, sizeof(lenCnt));
    memset(vis, 0, sizeof(vis));
    scanf("%d", &n);
    printf("n %d\n", n);
    for(int i = 0; i < n; i++) {
        char str[M];
        scanf("%s", str);
        // printf("%s\n", str);
        seg[i] = Seg(str);
        lenCnt[seg[i].len]++;
        idx[i] = i;
    }
    bool first = true;
    for(int i = 1; i <= M; i++) {
        if(lenCnt[i] <= 0)
            continue;
        char minc = '9';
        for(int j = 0; j < n; j++)
        x = i;
    }
    return 0;
}