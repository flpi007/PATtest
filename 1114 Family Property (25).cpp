#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 10000;
struct Person {
    int sets, area;
    Person(int ss = 0, int aa = 0): sets(ss), area(aa) {}
};
struct Family {
    int id, mem, sets, area;
    Family(int mm = 0, int ss = 0, int aa = 0)
    {
        mem = mm;
        sets = ss;
        area = aa;
        id = N + 1;
    }
    bool operator <(const Family &rhs) const
    {
        return ((area * rhs.mem > rhs.area * mem) \
                || (area * rhs.mem == rhs.area * mem && id < rhs.id));
    }
};
int n, vis[N];
vector<int> graph[N];
Person persons[N];
int main()
{
    memset(vis, -1, sizeof(vis));
    cin >> n;
    for(int i = 0; i < n; i++) {
        int id, fa, ma, k, mm, aa;
        cin >> id >> fa >> ma >> k;
        vis[id] = 0;
        if(~fa) {
            graph[id].push_back(fa);
            graph[fa].push_back(id);
            vis[fa] = 0;
        }
        if(~ma) {
            graph[id].push_back(ma);
            graph[ma].push_back(id);
            vis[ma] = 0;
        }
        for(int j = 0; j < k; j++) {
            int child;
            cin >> child;
            graph[id].push_back(child);
            graph[child].push_back(id);
            vis[child] = 0;
        }
        cin >> mm >> aa;
        persons[id] = Person(mm, aa);
    }
    //flood fill
    vector<Family> families;
    for(int i = 0; i < N; i++) {
        if(vis[i] == 0) {
            Family fam;
            queue<int> q;
            q.push(i);
            vis[i] = 1;
            while(!q.empty()) {
                int u = q.front(); q.pop();
                fam.id = min(fam.id, u);
                fam.mem++;
                fam.sets += persons[u].sets;
                fam.area += persons[u].area;
                for(int j = 0; j < graph[u].size(); j++) {
                    int nxt = graph[u][j];
                    if(vis[nxt] == 0) {
                        q.push(nxt);
                        vis[nxt] = 1;
                    }
                }
            }
            families.push_back(fam);
        }
    }
    sort(families.begin(), families.end());
    printf("%ld\n", families.size());
    for(auto i = families.begin(); i!=families.end(); i++){
        double aveS, aveA;
        aveS = i->sets / (double) i->mem;
        aveA = i->area / (double) i->mem;
        printf("%04d %d %.3f %.3f\n", i->id, i->mem, aveS, aveA);
    }
    return 0;
}