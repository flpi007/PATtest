#include <cstdio>
#include <set>
#include <vector>
using namespace std;

struct Edge {
    int u, v;
    Edge(int a, int b): u(a), v(b) {}
};
int n, m, k;
vector<Edge> edges;
int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        edges.push_back(Edge(a, b));
    }
    scanf("%d", &k);
    for(int i = 0; i < k; i++) {
        set<int> vers;
        int nv;
        scanf("%d", &nv);
        for(int j = 0; j < nv; j++) {
            int v;
            scanf("%d", &v);
            vers.insert(v);
        }
        bool valid = true;
        for(auto it = edges.begin(); it != edges.end(); it++) {
            if(vers.find(it->u) == vers.end() && vers.find(it->v) == vers.end()) {
                valid = false;
                break;
            }
        }
        if(valid) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}