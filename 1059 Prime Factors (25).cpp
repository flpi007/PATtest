#include <cstdio>
#include <cstring>
#include <cmath>

const int N = 60;
long n, t, p[N];
int k[N], cnt;
int isPrime(long x)
{
    for(int i = 0; i < cnt && p[i] < x; i++) {
        if(x % p[i] == 0)
            return 0;
    }
    return 1;
}
int main()
{
    memset(k, 0, sizeof(k));
    scanf("%ld", &n);
    t = n;
    cnt = 0;
    p[0] = 1;
    long i = 2;
    while(i <= long(sqrt(t))) {
        if(t % i == 0 && isPrime(i)) {
            p[cnt] = i;
            while(t % i == 0) {
                t = t / i;
                k[cnt]++;
            }
            cnt++;
        }
        i++;
    }
    if(t>i && isPrime(t)){
        p[cnt] = t;
        k[cnt++] = 1;
    }
    printf("%ld=", n);
    printf("%ld", p[0]);
    if(k[0] > 1)
        printf("^%d", k[0]);
    for(int i = 1; i < cnt; i++) {
        printf("*%ld", p[i]);
        if(k[i] > 1)
            printf("^%d", k[i]);
    }
    return 0;
}