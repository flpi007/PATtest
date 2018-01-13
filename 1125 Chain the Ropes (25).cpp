#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

const int N = 10000;
int n;
multiset<double> ropes;
int main()
{
    cin >> n;
    for(int i = 0; i < n; i++) {
        double t;
        cin >> t;
        ropes.insert(t);
    }
    while(ropes.size() > 1) {
        double a = *(ropes.begin());
        ropes.erase(ropes.begin());
        double b = *(ropes.begin());
        ropes.erase(ropes.begin());
        // printf("%.2lf %.2lf\n", a, b);
        ropes.insert((a + b) / 2.0);
    }
    cout << int(*ropes.begin()) << endl;
    return 0;
}