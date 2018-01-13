#include <cstdio>
const int d[] = {0, 17, 29};
int main()
{
    int a[3], b[3];
    scanf("%d.%d.%d", &a[0], &a[1], &a[2]);
    scanf("%d.%d.%d", &b[0], &b[1], &b[2]);
    int c = 0;
    for(int i = 2; i > 0; i--) {
        a[i] = a[i] + b[i] + c;
        c = a[i] / d[i];
        a[i] = a[i] % d[i];
    }
    a[0] = a[0] + b[0] + c;
    printf("%d.%d.%d", a[0], a[1], a[2]);
}