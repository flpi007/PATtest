#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int N = 20, M = 10, K = 1000, Q = 1000;
const int START = 480, END = 1020;

int n, m, k, q;
int procet[K], servt[K];
queue<int> yeloQue[Q];
queue<int> que;
int wint[Q];
void Tprint(int x, const char *s)
{
    int hh = x / 60;
    int mm = x % 60;
    printf(s, hh, mm);
}
int minQue()
{
    int ans = -1, minq = m;
    for(int i = 0; i < n; i++) {
        if(yeloQue[i].size() < minq) {
            minq = yeloQue[i].size();
            ans = i;
        }
    }
    return ans;
}
int main()
{
    memset(servt, -1, sizeof(servt));
    scanf("%d%d%d%d", &n, &m, &k, &q);
    for(int i = 0; i < k; i++) {
        scanf("%d", &procet[i]);
    }
    for(int i = 0; i < n; i++) {
        wint[i] = 0;
    }
    for(int i = 0; i < k; i++) {
        que.push(i);
    }
    for(int t = START; t < END; t++) {
        //at the beginning of t minute
        //serv out
        for(int i = 0; i < n; i++) {
            if(yeloQue[i].size() > 0 && wint[i] >= procet[yeloQue[i].front()]) {
                yeloQue[i].pop();
                wint[i] = 0;
            }
        }
        //move in
        while(que.size() > 0 && minQue() != -1) {
            int qid = minQue();
            int id = que.front(); que.pop();
            yeloQue[qid].push(id);
        }
        //pending & incre t
        for(int i = 0; i < n; i++) {
            if(yeloQue[i].size() > 0) {
                if(wint[i] == 0) {
                    servt[yeloQue[i].front()] = t;
                }
                wint[i]++;
            }
        }
    }
    for(int i = 0; i < q; i++) {
        int id;
        scanf("%d", &id);
        id--;
        if(servt[id] == -1) {
            printf("Sorry\n");
        } else {
            Tprint(servt[id] + procet[id], "%02d:%02d\n");
        }
    }
    // for(int i = 0; i < k; i++) {
    //     Tprint(servt[i], "serv:%02d:%02d ");
    //     Tprint(servt[i] + procet[i], " end:%02d:%02d\n");
    // }
    return 0;
}