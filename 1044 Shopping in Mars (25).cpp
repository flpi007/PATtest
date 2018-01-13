#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100010;
const long long M = 0x7fffffffffffffff;
int n;
long long d[N], delta[N], m;
int idx[N], tail[N];
bool Comp(int a,int b){
	return delta[a] < delta[b] || (delta[a] == delta[b] && a < b);
}
int main()
{
    scanf("%d%lld", &n, &m);
    for(int i = 0; i < n; i++) {
        scanf("%lld", &d[i]);
        idx[i] = i;
    }
    int i = 0, j = 0;
    long long sum = 0;
    for(; i < n; i++) {
    	j = (j<i) ? i : j;
        while(sum < m && j < n) {
            sum += d[j++];
        }
        tail[i] = j;
        delta[i] = sum >= m ? sum - m : M;
        if(j>i)
            sum -= d[i];
    }
    sort(idx, idx+n, Comp);
    printf("%d-%d\n", idx[0] + 1, tail[idx[0]]);
    for(int i=1; delta[idx[i]] == delta[idx[0]] && i < n; i++)
    	printf("%d-%d\n", idx[i] + 1, tail[idx[i]]);
    // for(int i=0; i<n; i++)
    //     printf("%lld ", delta[i]);
    return 0;
}