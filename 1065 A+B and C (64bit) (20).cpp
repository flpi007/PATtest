#include <cstdio>

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        printf("Case #%d: ", i + 1);
        long long a, b, c;
        scanf("%lld%lld%lld", &a, &b, &c);
        long long t = a + b;
        if(a > 0 && b > 0 && t <= 0) { //overflow
            printf("true\n");
        } else if(a < 0 && b < 0 && t >= 0) {
            printf("false\n");
        } else {
            if(t <= c) {//normal case
                printf("false\n");
            } else {
                printf("true\n");
            }
        }
    }
    long long a, b, t;
    a = 0x8000000000000000;
    b = 0;
    t = a + b;
    printf("%d %d\n", a + b < 0 , t < 0);
    return 0;
}