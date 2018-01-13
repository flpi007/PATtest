#include <cstdio>
#include <cstring>
#include <cctype>
#include <vector>
#include <queue>
using namespace std;

const int N = 20;
int vis[N], left[N], right[N];
int n;
int main()
{
    memset(vis, 0, sizeof(vis));
    memset(left, -1, sizeof(left));
    memset(right, -1, sizeof(right));
    scanf("%d\n", &n);
    for(int i = 0; i < n; i++) {
        int a = -1, b = -1;
        char str[64];
        fgets(str, 64, stdin);
        if(str[0] == '-') {
            sscanf(str + 1, "%d", &b);
        } else {
            if(sscanf(str, "%d%d", &a, &b) == 1) {
                b = -1;
            }
        }
        // printf("%d %d\n", a, b);
        if(a != -1) {
            left[i] = a;
            vis[a] = 1;
        }
        if(b != -1) {
            right[i] = b;
            vis[b] = 1;
        }
    }
    int root = -1;
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            root = i;
            break;
        }
    }
    bool complete = true;
    int cnt = 0, u;
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        if(q.front() == -1){
            if(cnt == n){
                complete = true;
            }else{
                complete = false;
            }
            break;
        }
        u = q.front(); q.pop();
        cnt++;
        q.push(left[u]);
        q.push(right[u]);
    }
    if(complete) {
        printf("YES %d\n", u);
    } else {
        printf("NO %d\n", root);
    }
    return 0;
}