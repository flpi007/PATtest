#include <cstdio>
#include <cstring>

const int N=100000;
int n, cnt = 0;
int vis[N];
int idx[N];
int main(){
	memset(vis, 0, sizeof(vis));
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int t;
		scanf("%d",&t);
		if(vis[t]++ == 0)
			idx[cnt++] = t;
	}
	for(int i=0;i<cnt;i++)
		if(vis[idx[i]]==1){
			printf("%d\n", idx[i]);
			return 0;
		}
	printf("None\n");
	return 0;
}