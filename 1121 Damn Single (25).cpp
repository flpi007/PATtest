#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int M = 100007;
int couple[M], vis[M];
int n, m;
int main()
{
    memset(couple, -1, sizeof(couple));
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        couple[a] = b;
        couple[b] = a;
    }
    cin >> m;
    vector<int> party;
    for(int i = 0; i < m; i++) {
        int a;
        cin >> a;
        party.push_back(a);
        vis[a] = 1;
    }
    vector<int> singles;
    for(int i = 0; i < m; i++) {
        // printf("%d\n", i);
        int id = party[i];
        if(couple[id] == -1 || vis[couple[id]] == 0) {
            singles.push_back(id);
        }
    }
    sort(singles.begin(), singles.end());
    printf("%ld\n", singles.size());
    for(int i = 0; i < singles.size(); i++) {
        if(i) {
            printf(" ");
        }
        printf("%05d", singles[i]);
    }
    return 0;
}