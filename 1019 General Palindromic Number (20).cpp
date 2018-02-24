#include <cstdio>
#include <vector>
using namespace std;

long long n, b, t;
int main(){
    scanf("%lld%lld", &n, &b);
    vector<long long> digits;
    do{ //n=0 => digits(0)
        t = n % b;
        digits.push_back(t);
        n = n / b;
    }while(n != 0);
    bool valid = true;
    long s = digits.size();
    for(long i=0; i<s / 2; i++){
        if(digits[i] != digits[s - 1 - i]){
            valid = false;
            break;
        }
    }
    if(valid){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    for(long i = s - 1; i>0; i--){
        printf("%lld ", digits[i]);
    }
    printf("%lld\n", digits[0]);
    return 0;
}