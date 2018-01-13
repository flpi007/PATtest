#include <iostream>
#include <algorithm>
using namespace std;

struct Rational
{
    int num, den;
    Rational(int nn = 0, int dd = 1):num(nn), den(dd){};
    int gcd(int a, int b){
        a = abs(a);
        if(a > b){
            swap(a, b);
        }
        while(a > 0){
            int c = b % a;
            b = a;
            a = c;
        }
        return b;
    }
    void simplify(){
        int p = gcd(num, den);
        num /= p;
        den /= p;
    }
    Rational operator +(const Rational &rhs) const {
        Rational c;
        c.num = num * rhs.den + rhs.num * den;
        c.den = den * rhs.den;
        c.simplify();
        return c;
    }
};
int n;
int main(){
    cin >> n;
    Rational s = Rational(0, 1);
    for(int i=0; i<n; i++){
        int a, b;
        scanf("%d/%d", &a, &b);
        s = s + Rational(a, b);
        // printf("+%d/%d = %d/%d\n", a, b, s.num, s.den);
    }
    int a = s.num, b = s.den;
    if(b == 1){
        printf("%d\n", a);
    }else if(abs(a) > b){
        printf("%d %d/%d\n", a / b, abs(a) % b, b);
    }else if(abs(a) > 0){
        printf("%d/%d\n", a, b);
    }else{
        printf("0\n");
    }
    return 0;
}