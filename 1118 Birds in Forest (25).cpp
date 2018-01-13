#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <vector>
using namespace std;

const int N = 10007, Q = 10007, M = 10007;
int n, q;
int parent[M];
int findP(int u){
    if(parent[u] == -1 || parent[u] == u){
        return u;
    }else{
        return parent[u] = findP(parent[u]);
    }
}
int main(){
    memset(parent, -1, sizeof(parent));
    cin >> n;
    for(int i=0; i<n; i++){
        int k, root;
        cin >> k >> root;
        if(parent[root] == -1){
            parent[root] = root;
        }
        for(int j=1; j<k; j++){
            int child;
            cin >> child;
            if(parent[child] == -1){
                parent[child] = root;
            }else{
                parent[findP(child)] = parent[root];
            }
        }
    }
    int nbirds = 0;
    set<int> parents;
    for(int i=0; i<M; i++){
        if(parent[i] != -1){
            nbirds++;
            int p = findP(i);
            if(parents.find(p) == parents.end()){
                parents.insert(p);
            }
        }
    }
    printf("%ld %d\n", parents.size(), nbirds);
    cin >> q;
    for(int i=0; i<q; i++){
        int a, b;
        cin >> a >> b;
        if(parent[a] == parent[b] && parent[a] != -1){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
    return 0;
}