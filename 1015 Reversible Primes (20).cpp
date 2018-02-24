#include <cstdio>

long n, d;
bool isPrime(int x)
{
    for(int i = 2; i * i <= x; i++) {
        if(x % i == 0) {
            return false;
        }
    }
    return x != 0 && x != 1;
}
int main()
{
    while(scanf("%ld%ld", &n, &d) && n > 0) {
        long rn = 0, t = n;
        while(t != 0) {
            rn = rn * d + (t % d);
            t = t / d;
        }
        if(isPrime(n) && isPrime(rn)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}