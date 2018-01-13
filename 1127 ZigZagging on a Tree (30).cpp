#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
using namespace std;

const int N = 37;
int n;
int in[N], post[N];
int left[N], right[N];
int build(int p, int f, int e)
{
    if(f >= e) {
        return -1;
    } else {
        // printf("%d:%d\n", in[f], in[e - 1]);
        int pivot = post[p];
        for(int i = f; i < e; i++) {
            if(in[i] == pivot) {
                left[p] = build(p - e + i , f, i);
                right[p] = build(p - 1, i + 1, e);
                break;
            }
        }
        return p;
    }
}
void printd(int d)
{
    static bool first = true;
    if(!first) {
        printf(" ");
    } else {
        first = false;
    }
    printf("%d", d);
}
int main()
{
    memset(left, -1, sizeof(left));
    memset(right, -1, sizeof(right));
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &in[i]);
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", &post[i]);
    }
    build(n - 1, 0, n);

    int dir = 0, flag = 0;;
    queue<int> q;
    stack<int> buffer;
    q.push(n - 1);
    q.push(-2);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        if(u == -2) {
            dir = !dir; //flop
            flag = 1;
        } else if(u != -1) {
            if(!dir) {
                buffer.push(post[u]);
            } else {
                while(!buffer.empty()) {
                    int d = buffer.top(); buffer.pop();
                    printd(d);
                }
                printd(post[u]);
            }
            if(flag) {
                q.push(-2);
                flag = 0;
            }
            q.push(left[u]);
            q.push(right[u]);
        }
    }
    while(!buffer.empty()) {
        int d = buffer.top(); buffer.pop();
        printd(d);
    }
    printf("\n");
    return 0;
}
