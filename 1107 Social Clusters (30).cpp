#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

const int N = 1007, M = 1007;
struct Node
{
    int k;
    int h[M];
    Node(){
        memset(h, 0, sizeof(h));
    }
};
Node nodes[N];
int clus[N], com[N][N];
int n;
int common(int a, int b){
    if(com[a][b] != -1){
        return com[a][b];
    }else{
        for(int i=0; i<M; i++){
            if(nodes[a].h[i] && nodes[b].h[i]){
                return com[a][b] = 1;
            }
        }
        return com[a][b] = 0;
    }
}
int main(){
    memset(clus, 0, sizeof(clus));
    memset(com, -1, sizeof(com));
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> nodes[i].k;
        getchar();
        for(int j=0; j<nodes[i].k; j++){
            int t;
            cin >> t;
            nodes[i].h[t] = 1;
        }
    }
    //floodfill
    vector<int> cnts;
    for(int i=0; i<n; i++){
        if(!clus[i]){
            int cnt = 0;
            queue<int> q;
            clus[i] = 1;
            q.push(i);
            while(!q.empty()){
                int u = q.front(); q.pop();
                cnt++;
                for(int j=0; j<n; j++){
                    if(!clus[j] && common(u, j)){
                        clus[j] = 1;
                        q.push(j);
                    }
                }
            }
            cnts.push_back(cnt);
        }
    }
    sort(cnts.begin(), cnts.end(), greater<int>());
    printf("%ld\n", cnts.size());
    for(int i=0; i<cnts.size(); i++){
        if(i){
            printf(" ");
        }
        printf("%d", cnts[i]);
    }
    printf("\n");
    return 0;
}