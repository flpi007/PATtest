#include <cstdio>
#include <cstring>
#include <queue>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 10000 + 10, K = 100 + 10;
const int START = 28800, END = 75600;
struct Tables {
    int k;
    int tags[K], stat[K], cnt[K];
    Tables()
    {
        memset(stat, 0, sizeof(stat));
        memset(cnt, 0, sizeof(cnt));
    }
    void init(int kk)
    {
        k = kk;
        for(int i = 0; i < K; i++) {
            tags[i] = 0b01;
        }
    }
    void tagj(int j)
    {
        tags[j] = 0b10;
    }
    int isfree(int t, int tagm)
    {
        for(int i = 0; i < k; i++) {
            if((tags[i] & tagm) && stat[i] <= t) {
                return i;
            }
        }
        return -1;
    }
    void take(int id, int et)
    {
        stat[id] = et;
        cnt[id]++;
    }
};
struct Players {
    static const int maxN = END + 10;
    int pt[maxN], tags[maxN]; //use arriving time as index
    Players()
    {
        memset(pt, 0, sizeof(pt));
        memset(tags, -1, sizeof(tags));
    }
    int arrived(int t, int *tag)
    {
        if(tags[t] != -1) {
            *tag = tags[t];
            return 1;
        } else {
            return 0;
        }
    }
};
int n, k, m;
Tables tables;
Players players;
queue<int> p[2];
void PrintT(int a, const char *s)
{
    int hh, mm, ss;
    hh = a / 3600; a %= 3600;
    mm = a / 60; a %= 60;
    ss = a;
    printf(s, hh, mm, ss);
}
void servplayer(int table, int t, int tag)
{
    int at = p[tag].front(); p[tag].pop();

    PrintT(at, "%02d:%02d:%02d ");
    PrintT(t, "%02d:%02d:%02d ");
    int delta = (t - at + 30) / 60;
    printf("%d\n", delta);

    int pt = players.pt[at];
    tables.take(table, t + pt);
}
int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int hh, mm, ss, playt, tag;
        scanf("%d:%d:%d%d%d", &hh, &mm, &ss, &playt, &tag);
        int t = hh * 3600 + mm * 60 + ss;
        if(t < END && t >= START) {
            players.pt[t] = (playt >= 2 * 60) ? 2 * 3600 : playt * 60;
            players.tags[t] = tag;
        }
    }
    scanf("%d%d", &k, &m);
    tables.init(k);
    for(int i = 0; i < m; i++) {
        int j;
        scanf("%d", &j);
        tables.tagj(j - 1);
    }
    for(int t = START; t < END; t++) {
        int tag;
        if(players.arrived(t, &tag)) {
            p[tag].push(t);
        }
        int table = -1;
        while(!p[1].empty() &&\
        (table = tables.isfree(t, 0b10)) != -1) { //preemption
            servplayer(table, t, 1);
        }
        while((table = tables.isfree(t, 0b11)) != -1) {
            if(!p[1].empty() && (p[0].empty() || p[1].front() <= p[0].front())) {
                servplayer(table, t, 1);
            } else if(!p[0].empty()) {
                servplayer(table, t, 0);
            } else {
                break;
            }
        }
    }
    for(int i = 0; i < k; i++) {
        if(i) {
            printf(" ");
        }
        printf("%d", tables.cnt[i]);
    }
    printf("\n");
    return 0;
}