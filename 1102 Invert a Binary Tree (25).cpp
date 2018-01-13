#include <cstdio>
#include <cstring>
#include <cctype>
#include <queue>
using namespace std;

const int N = 10;
int n;
int left[N], right[N], vis[N];
void bfs(int root){
    queue<int> q;
    q.push(root);
    bool nfirst = false;
    while(!q.empty()){
        int u = q.front(); q.pop();
        if(nfirst){
            printf(" ");
        }else{
            nfirst = true;
        }
        printf("%d", u);
        if(left[u] != -1){
            q.push(left[u]);
        }
        if(right[u] != -1){
            q.push(right[u]);
        }
    }
}
bool nfirst = false;
void inorder(int u){
    if(left[u] != -1){
        inorder(left[u]);
    }
    if(nfirst){
        printf(" ");
    }else{
        nfirst = true;
    }
    printf("%d", u);
    if(right[u] != -1){
        inorder(right[u]);
    }
}
int main(){
    memset(vis, 0, sizeof(vis));
    memset(right, -1, sizeof(right));
    memset(left, -1, sizeof(left));
    scanf("%d\n", &n);
    for(int i=0; i<n; i++){
        char a, b;
        scanf("%c %c\n", &a, &b);
        if(isdigit(a)){
            right[i] = a - '0';
            vis[a - '0'] = 1;
        }
        if(isdigit(b)){
            left[i] = b - '0';
            vis[b - '0'] = 1;
        }
    }
    for(int i=0; i<n; i++){
        if(!vis[i]){
            bfs(i);
            printf("\n");
            inorder(i);
            printf("\n");
            break;
        }
    }
    return 0;
}