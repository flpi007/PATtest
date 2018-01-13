#include <cstdio>
#include <cstring>
#include <functional>
#include <algorithm>
using namespace std;

const int END = 6174;
struct Digit {
    static const int M = 4;
    int d[M], val;
    Digit() {}
    Digit(int x)
    {
        val = x;
        for(int i = 0; i < M; i++) {
            d[i] = x % 10;
            x = x / 10;
        }
    }
    Digit(const Digit &a){
        val = a.val;
        memcpy(d, a.d, sizeof(d));
    }
    void Dsort(int b){
        if(!b)
            sort(d, d+M, greater<int>());
        else
            sort(d, d+M, less<int>());
        val = 0;
        for(int i=M-1;i>=0;i--)
            val = val * 10 + d[i];
    }
};
int n;
int main()
{
    scanf("%d", &n);
    Digit a, b, c;
    a = b = Digit(n);
    bool isvalid = false;
    for(int i=1;i<a.M;i++)
        if(a.d[i] != a.d[i-1]){
            isvalid = true;
            break;
        }
    if(!isvalid) {
        printf("%04d - %04d = 0000\n", a.val, a.val);
        return 0;
    }
    while(1){
        a.Dsort(1); b.Dsort(0);
        c = Digit(a.val - b.val);
        printf("%04d - %04d = %04d\n", a.val, b.val, c.val);
        if(c.val == END)
            break;
        a = c;
        b = c;
    }
    return 0;
}