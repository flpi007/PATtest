#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

const int S = 10;
int n, m, k;
map<string, vector<string>> G;
map<string, int> gender;
set<string> vers;
bool isConnect(string u, string v)
{
    for(auto &i : G[u]) {
        if(i == v) {
            return true;
        }
    }
    return false;
}
void findWay(string a, string b, vector<pair<string, string>> &l)
{
    // a-u-v-b
    for(auto &u : G[a]) {
        if(u != b && (gender[u] ^ gender[a] == 0)) {
            for(auto &v : G[b]) {
                if(v != a && (gender[v] ^ gender[b] == 0)) {
                    if(isConnect(u, v)) {
                        l.push_back(make_pair(u, v));
                    }
                }
            }
        }
    }
}
void read(string &a, string &b){
    char s1[S], s2[S];
    char *x, *y;
    scanf("%s%s", s1, s2);
    if(*s1 == '-'){
        x = s1 + 1;
        a = string(x);
        gender[a] = 1;
    }else{
        a = string(s1);
        gender[a] = 0;
    }
    if(*s2 == '-'){
        y = s2 + 1;
        b = string(y);
        gender[b] = 1;
    }else{
        b = string(s2);
        gender[b] = 0;
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++) {
        string a, b;
        read(a, b);
        G[a].push_back(b);
        G[b].push_back(a);
        vers.insert(a); vers.insert(b);
    }
    for(auto &i : vers) {
        sort(G[i].begin(), G[i].end());
    }
    scanf("%d", &k);
    for(int i = 0; i < k; i++) {
        string a, b;
        read(a, b);
        vector<pair<string, string>> list;
        findWay(a, b, list);
        printf("%ld\n", list.size());
        for(auto &j : list) {
            const char *u = j.first.c_str();
            const char *v = j.second.c_str();
            printf("%s %s\n", u, v);
        }
    }
    return 0;
}