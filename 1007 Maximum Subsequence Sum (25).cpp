#include <cstdio>
using namespace std;

const int K = 10000;
int k;
int a[K];
int main()
{
    scanf("%d", &k);
    for(int i = 0; i < k; i++) {
        scanf("%d", &a[i]);
    }
    int psum = 0, pi = 0;
    int maxs = 0, maxi = -1, maxj = -1; // [i, j]
    for(int j = 0; j < k; j++) {
        if(psum + a[j] > maxs || (psum + a[j] == maxs && maxs == 0)) {
            maxs = psum + a[j];
            maxj = j;
            maxi = pi;
        }
        if(psum + a[j] < 0) {
            psum = 0;
            pi = j + 1;
        } else {
            psum += a[j];
        }
    }
    if(maxs == 0 && maxi == -1) {
        maxi = 0;
        maxj = k - 1;
    }
    printf("%d %d %d\n", maxs, a[maxi], a[maxj]);
    return 0;
}