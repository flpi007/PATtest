#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

const int M = 100, K = 5;
multimap<string, int> maps[K];
int n, m;
void init()
{
    int id;
    cin >> id;
    getchar();
    for(int i = 0; i < K; i++) {
        if(i != 2) {
            string l;
            getline(cin, l);
            maps[i].insert(make_pair(l, id));
        } else {
            string str;
            getline(cin, str);
            str += ' ';
            string l;
            for(int j = 0; j < str.size(); j++) {
                if(str[j] != ' ') {
                    l += str[j];
                } else {
                    // printf("%s\n", l.c_str());
                    maps[i].insert(make_pair(l, id));
                    l = string();
                }
            }
        }
    }
}
int main()
{
    cin >> n;
    getchar();
    for(int i = 0; i < n; i++) {
        init();
    }
    cin >> m;
    getchar();
    for(int i = 0; i < m; i++) {
        int idx;
        cin >> idx;
        getchar();
        getchar();
        string l;
        getline(cin, l);
        printf("%d: %s\n", idx, l.c_str());
        idx--;
        vector<int> ans;
        for(multimap<string, int>::iterator j = maps[idx].find(l); \
            j != maps[idx].end() && j->first == l; j++) {
            ans.push_back(j->second);
        }
        if(ans.size() > 0) {
            sort(ans.begin(), ans.end());
            for(vector<int>::iterator j = ans.begin(); j != ans.end(); j++) {
                printf("%07d\n", *j);
            }
        } else {
            printf("Not Found\n");
        }
    }
    return 0;
}