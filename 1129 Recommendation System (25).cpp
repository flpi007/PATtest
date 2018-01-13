#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

const int N = 50007;
struct Log {
    int freq, idx;
    Log(int ff = 0, int ii = 0)
    {
        freq = ff;
        idx = ii;
    }
    bool operator <(const Log &rhs) const
    {
        return freq > rhs.freq || (freq == rhs.freq && idx < rhs.idx);
    }
};
int n, k, id;
int cnt[N];
set<Log> logs;
int main()
{
    cin >> n >> k >> id;
    logs.insert(Log(1, id));
    cnt[id]++;
    for(int i = 1; i < n; i++) {
        cin >> id;
        printf("%d:", id);
        auto p = logs.begin();
        for(int j = 0; j < k && p != logs.end(); j++, p++) {
            printf(" %d", p->idx);
        }
        printf("\n");
        if(cnt[id] == 0) {
            cnt[id]++;
            logs.insert(Log(1, id));
        } else {
            logs.erase(logs.find(Log(cnt[id], id)));
            cnt[id]++;
            logs.insert(Log(cnt[id], id));
        }
    }
    return 0;
}