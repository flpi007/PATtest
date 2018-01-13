#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 10000, K = 5, M = 100000;
int n, m, k;
int p[K];
struct User {
    int s[K];
    int total, solved, active;
    User()
    {
        total = solved = active = 0;
        memset(s, -1, sizeof(s));
    }
    void Update(int pi, int score)
    {
        if(score == -1)
            score = 0;
        else
            active = 1;
        if(score > s[pi]) {
            total += s[pi] == -1 ? score : score - s[pi];
            s[pi] = score;
            solved += s[pi] == p[pi] ? 1 : 0;
        }
    }
    void Print(int rank, int uid) const
    {
        if(!active)
            return;
        printf("%d %05d %d", rank, uid, total);
        for(int i = 0; i < k; i++) {
            if(s[i] != -1)
                printf(" %d", s[i]);
            else
                printf(" -");
        }
        printf("\n");
    }
};
User u[N];
int idx[N];
bool Comp(int a, int b) //index a,b
{
    const User &l = u[a];
    const User &r = u[b];
    if(l.total > r.total || (l.total == r.total && l.solved > r.solved) ||\
       (l.total == r.total && l.solved == r.solved && a < b))
        return true;
    return false;
}
int main()
{
    scanf("%d%d%d\n", &n, &k, &m);
    for(int i = 0; i < n; i++) {
        idx[i] = i;
    }
    for(int i = 0; i < k; i++)
        scanf("%d", &p[i]);
    for(int i = 0; i < m; i++) {
        int ui, pi, score;
        scanf("%d%d%d", &ui, &pi, &score);
        ui--; pi--;
        u[ui].Update(pi, score);
    }
    sort(idx, idx + n, Comp);
    int rank = 0;
    u[idx[0]].Print(rank + 1, idx[0] + 1);
    for(int i = 1; i < n; i++) {
        if(u[idx[i-1]].total!=u[idx[i]].total)
            rank = i;
        u[idx[i]].Print(rank + 1, idx[i] + 1);
    }
    return 0;
}