#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;

const int N = 100007;
int n, k;
int d[N], nxt[N];
int main()
{
    memset(nxt, -1, sizeof(nxt));
    int root;
    scanf("%d%d%d", &root, &n, &k);
    for(int i = 0; i < n; i++) {
        int addr, data, next;
        scanf("%d%d%d", &addr, &data, &next);
        d[addr] = data;
        nxt[addr] = next;
    }
    vector<int> raddr;
    stack<int> s;
    int u = root;
    for(; u != -1; u = nxt[u]) {
        s.push(u);
        if(s.size() >= k) {
            while(!s.empty()) {
                int v = s.top(); s.pop();
                raddr.push_back(v);
            }
        }
    }
    if(!s.empty()){
        stack<int> ss;
        while(!s.empty()){
            int v = s.top(); s.pop();
            ss.push(v);
        }
        while(!ss.empty()){
            int v = ss.top(); ss.pop();
            raddr.push_back(v);
        }
    }
    for(int i = 0; i < raddr.size() - 1 ; i++) {
        int addr = raddr[i];
        printf("%05d %d %05d\n", addr, d[addr], raddr[i+1]);
    }
    int i = raddr.size() - 1;
    printf("%05d %d -1\n", raddr[i], d[raddr[i]]);
    return 0;
}