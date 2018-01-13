#include <cstdio>
#include <cstring>

int n;
int main()
{
    scanf("%d\n", &n);
    double sum = 0;
    for(int i = 0; i < n; i++) {
        double t;
        scanf("%lf", &t);
        sum += t * (n - i) * (i + 1);
    }
    printf("%.2lf\n", sum);
    return 0;
}