#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

map<int, int> a;
int main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            int t;
            scanf("%d", &t);
            if(a.find(t) != a.end()) {
                a[t]++;
            } else {
                a[t] = 1;
            }
        }
    int half = m * n / 2;
    for(map<int, int>::iterator i = a.begin(); i != a.end(); i++) {
        if(i->second > half) {
            printf("%d\n", i->first);
            break;
        }
    }
    return 0;
}