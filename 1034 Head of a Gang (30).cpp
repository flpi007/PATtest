#include <cstdio>
#include <cstring>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

const int N = 2100, K = 2100, M = 20000, L = 4;
struct Name
{
    char s[L];
    Name(){}
    Name(char *ss){
        strcpy(s, ss);
    }
    bool operator <(const Name &rhs) const {
        return strcmp(s, rhs.s) < 0;
    }
};
int n, k;
int e[N][N], w[N], cnt;
int head[N], nMem[N];
Name name[K];
map<Name, int> se;
bool Comp(int a, int b)
{
    return name[head[a]] < name[head[b]];
}
int main()
{
    memset(e, 0, sizeof(e));
    memset(w, 0, sizeof(w));
    cnt = 0;
    scanf("%d%d\n", &n, &k);
    k = k * 2;
    for(int i = 0; i < n; i++) {
        char a[L], b[L];
        int t;
        scanf("%s %s %d\n", a, b, &t);
        Name un = Name(a), vn = Name(b);
        if(se.find(un) == se.end()) {
            se[un] = cnt;
            name[cnt++] = un;
        }
        if(se.find(vn) == se.end()) {
            se[vn] = cnt;
            name[cnt++] = vn;
        }
        int u = se[un], v = se[vn];
        e[u][v] = e[v][u] = 1;
        w[u] += t;
        w[v] += t;
    }

    int color = 0;
    int vis[N];
    memset(vis, -1, sizeof(vis));
    for(int i = 0; i < cnt; i++) { //flood fill
        if(vis[i] != -1)
            continue;
        queue<int> q;
        q.push(i);
        vis[i] = color;
        int nNode = 0, total = 0;
        head[color] = i;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            nNode++;
            total += w[u];
            if(w[u] > w[head[color]])
                head[color] = u;
            for(int j = 0; j < cnt; j++) {
                if(e[u][j] && vis[j] == -1) {
                    vis[j] = color;
                    q.push(j);
                }
            }
        }
        if(nNode > 2 && total > k) {
            nMem[color] = nNode;
            color++;
        }
    }
    printf("%d\n", color);
    int idx[N];
    for(int i = 0; i < color; i++)
        idx[i] = i;
    sort(idx, idx + color, Comp);
    for(int i = 0; i < color; i++) {
        printf("%s %d\n", name[head[idx[i]]].s, nMem[idx[i]]);
    }
    return 0;
}