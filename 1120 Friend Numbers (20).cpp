#include <iostream>
#include <cstdio>
using namespace std;

const int N = 128;
int n;
int vis[N], cnt;
int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        int t;
        cin >> t;
        int id = 0;
        while(t > 0){
            id += t % 10;
            t = t / 10;
        }
        // printf("%d\n", id);
        if(!vis[id]){
            cnt++;
            vis[id] = 1;            
        }
    }
    printf("%d\n", cnt);
    bool nfirst = false;
    for(int i=0; i<N; i++){
        if(vis[i]){
            if(nfirst){
                printf(" ");
            }else{
                nfirst = true;
            }
            printf("%d", i);
        }
    }
    printf("\n");
    return 0;
}