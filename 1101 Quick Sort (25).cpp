#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> a, b, ans;
int main()
{
    scanf("%d", &n);
    a.reserve(n);
    b.reserve(n);
    for(int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        a.push_back(t);
        b.push_back(t);
    }
    sort(b.begin(), b.end());
    int leftMax = a[0];
    for(int i = 0; i < n; i++) {
        if(a[i] == b[i] && leftMax <= b[i]) {
            ans.push_back(a[i]);
        }
        leftMax = max(leftMax, a[i]);
    }
    printf("%ld\n", ans.size());
    for(int i = 0; i < ans.size(); i++) {
        if(i) {
            printf(" ");
        }
        printf("%d", ans[i]);
    }
    printf("\n");
    return 0;
}