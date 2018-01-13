#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> a;
int main(){
    cin >> n;
    a.reserve(n);
    for(int i=0; i<n; i++){
        int t;
        cin >> t;
        a.push_back(t);
    }
    sort(a.begin(), a.end());
    int n2;
    n2 = n / 2;
    int dS;
    for(int i=0; i<n2; i++){
        dS += a[n2 + i] - a[i];
    }
    if(n2 * 2 < n){
        dS += a[n - 1];
        printf("%d %d\n", 1, dS);
    }else{
        printf("%d %d\n", 0, dS);
    }
    return 0;
}