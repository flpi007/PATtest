#include <cstdio>
#include <cstring>
#include <cctype>

const int N = 100;
char ori[N], to[N];
bool vis[256];
int main()
{
    memset(vis, 0, sizeof(vis));
    scanf("%s%s", ori, to);
    char *s = ori, *t = to;
    while(*s) {
        while(*s != *t) {
            if(vis[toupper(*s)] == 0) {
                vis[toupper(*s)] = 1;
                printf("%c", toupper(*s));
            }
            s++;
        }
        s++;
        if(*t) {
            t++;
        }
    }
    return 0;
}