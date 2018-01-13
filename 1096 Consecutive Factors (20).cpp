#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

const int N = 10000;
int n;
int getLen(int a)
{
    int t = n;
    for(int d = 0; d < 12; d++) {
        if(t % (a + d) != 0) return d;
        t /= (a + d);
    }
    return 12;
}
void printAns(int i, int d)
{
    printf("%d\n%d", d, i);
    for(int j = 1; j < d; j++)
        printf("*%d", i + j);
    printf("\n");
}
int main()
{
    scanf("%d", &n);
    int maxlen = 1, maxs = n;
    for(int i = 2; n / i > i; i++) {
        int t = getLen(i);
        if(t > maxlen || (t == maxlen && i < maxs)) {
            maxlen = t;
            maxs = i;
        }
    }
    printAns(maxs, maxlen);
    return 0;
}