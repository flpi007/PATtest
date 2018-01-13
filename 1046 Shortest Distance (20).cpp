#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100000, M = 10000;
int n,m;
int s[N + 1]; //s[i]=d[0->i]
int main(){
	scanf("%d", &n);
	int sum = 0;
	s[0] = sum;
	for(int i=1;i<=n;i++){
		int t;
		scanf("%d", &t);
		sum += t;
		s[i] = sum;
	}
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d %d", &a, &b);
		a--; b--;
		int d1 = (s[b] - s[a] + sum) % sum;
		int d2 = (s[a] - s[b] + sum) % sum;
		printf("%d\n", min(d1, d2));
	}
	return 0;
}