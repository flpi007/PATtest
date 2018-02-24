#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 100000;
int data[N], nxt[N];
int n, start, k;
bool Cmp(const int i, int j)
{
    int a = data[i], b = data[j];
    return (a < 0 && b >= 0) || (a <= k && b > k);
}
int main()
{
    scanf("%d%d%d", &start, &n, &k);
    for(int i = 0; i < n; i++) {
        int addr, d, ptr;
        scanf("%d%d%d", &addr, &d, &ptr);
        data[addr] = d;
        nxt[addr] = ptr;
    }
    vector<int> idx;
    for(int a = start; a != -1; a = nxt[a]) {
        idx.push_back(a);
    }
    stable_sort(idx.begin(), idx.end(), Cmp);
    for(int i = 0; i + 1 < idx.size(); i++) {
        int addr = idx[i];
        int ptr = idx[i + 1];
        printf("%05d %d %05d\n", addr, data[addr], ptr);
    }
    printf("%05d %d -1\n", *idx.rbegin(), data[*idx.rbegin()]);
    return 0;
}