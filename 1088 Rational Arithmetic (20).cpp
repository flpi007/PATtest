#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
ll gcd(ll a, ll b)
{
    int pos = (b >= 0) ? 1 : 0;
    a = abs(a);
    b = abs(b);
    if(a < b) {
        swap(a, b);
    } // |a| >= |b|
    while(b != 0) {
        ll c = a % b;
        a = b;
        b = c;
    }
    return (pos) ? a : -a;
}
struct Ra {
    ll num, den;
    Ra() {}
    Ra(ll nn, ll dd)
    {
        num = nn;
        den = dd;
        simp();
    }
    void simp()
    {
        ll f = gcd(num, den);
        num /= f;
        den /= f;
    }
    Ra operator +(const Ra &rhs) const
    {
        Ra t;
        t.den = den * rhs.den;
        t.num = num * rhs.den + rhs.num * den;
        t.simp();
        return t;
    }
    Ra operator -(const Ra &rhs) const
    {
        Ra t;
        t.den = den * rhs.den;
        t.num = num * rhs.den - rhs.num * den;
        t.simp();
        return t;
    }
    Ra operator *(const Ra &rhs) const
    {
        Ra t;
        t.den = den * rhs.den;
        t.num = num * rhs.num;
        t.simp();
        return t;
    }
    Ra operator /(const Ra &rhs) const
    {
        Ra t;
        t.den = den * rhs.num;
        t.num = num * rhs.den;
        t.simp();
        return t;
    }
    void print() const
    {
        if(den == 0) {
            printf("Inf");
        } else {
            ll i = num / den;
            ll n = num % den;
            if(num < 0) {
                printf("(-");
            }
            if(den == 1) {
                printf("%lld", abs(num));
            } else if(i != 0) {
                printf("%lld %lld/%lld", abs(i), abs(n), den);
            } else {
                printf("%lld/%lld", abs(n), den);
            }
            if(num < 0) {
                printf(")");
            }
        }
    }
};
void pform(const Ra &a, const Ra &b, const Ra &c, const char *s)
{
    a.print();
    printf(" %s ", s);
    b.print();
    printf(" = ");
    c.print();
    printf("\n");
}
int main()
{
    ll a, b, c, d;
    scanf("%lld/%lld %lld/%lld", &a, &b, &c, &d);
    Ra A(a, b), B(c, d);
    pform(A, B, A + B, "+");
    pform(A, B, A - B, "-");
    pform(A, B, A * B, "*");
    pform(A, B, A / B, "/");
    return 0;
}