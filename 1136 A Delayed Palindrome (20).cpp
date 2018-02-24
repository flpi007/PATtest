#include <cstdio>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1000;
struct BigInt {
    vector<int> a;
    BigInt() {}
    BigInt(char *s)
    {
        for(char *c = s; isdigit(*c); c++) {
            a.push_back(*c - '0');
        }
        reverse(a.begin(), a.end());
    }
    BigInt operator +(const BigInt &rhs) const
    {
        BigInt ans;
        int r = 0, x, y;
        for(int i = 0; i < a.size() || i < rhs.a.size() || r != 0; i++) {
            x = i < a.size() ? a[i] : 0;
            y = i < rhs.a.size() ? rhs.a[i] : 0;
            int t = x + y + r;
            r = t / 10;
            ans.a.push_back(t % 10);
        }
        return ans;
    }
    bool isPalin() const
    {
        int s = a.size();
        for(int i = 0; i < s / 2; i++) {
            if(a[i] != a[s - 1 - i]) {
                return false;
            }
        }
        return true;
    }
    void print(const char *s)
    {
        for(int i = a.size() - 1; i >= 0; i--) {
            printf("%d", a[i]);
        }
        printf("%s", s);
    }
};
char s[N];
int main()
{
    scanf("%s", s);
    BigInt a(s);
    bool valid = false;
    if(a.isPalin()) {
        valid = true;
    }
    int i = 0;
    while(i < 10 && !valid) {
        BigInt b = a;
        reverse(b.a.begin(), b.a.end());
        BigInt c = a + b;
        a.print(" + ");
        b.print(" = ");
        c.print("\n");
        a = c;
        if(c.isPalin()) {
            valid = true;
            break;
        }
        i++;
    }
    if(valid) {
        a.print(" is a palindromic number.\n");
    } else {
        printf("Not found in 10 iterations.\n");
    }
    return 0;
}