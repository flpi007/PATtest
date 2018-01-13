#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
using namespace std;

const int N = 207;
int n, m, k;
set<int> g[N];
int main(){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        g[a].insert(b);
        g[b].insert(a);
    }
    cin >> k;
    for(int i=0; i<k; i++){
        int nn, f, pre, t;
        bool hasLink = true;
        set<int> ver;
        cin >> nn >> f;
        pre = f;
        for(int j=1; j<nn; j++){
            cin >> t;
            if(ver.find(t) == ver.end()){
                ver.insert(t);
            }
            if(g[pre].find(t) == g[pre].end()){
                hasLink = false;
            }
            pre = t;
        }
        if(nn == n+1 && ver.size() == n && f == t && hasLink){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}