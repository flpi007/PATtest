#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;
int a[1000000];
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a+1, a+n+1, greater<int>());
    for(int i=1; i<n+1; i++){
        if(a[i] <= i){
            printf("%d\n", i - 1);
            return 0;
        }
    }
    printf("%d\n", n);
    return 0;
}