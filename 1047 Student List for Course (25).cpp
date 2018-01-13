#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 40000, K = 2500, C = 20;
struct Name {
    char s[5];
    Name()
    {
        memset(s, 0, sizeof(s));
    }
    bool operator <(const Name rhs) const
    {
        return strcmp(s ,rhs.s) < 0;
    }
};
int n, k;
Name names[N];
int idx[N];
vector<int> course[N];
bool Comp(int a, int b)
{
    return names[a] < names[b];
}
int main()
{
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++) {
        int c;
        scanf("%s%d", names[i].s, &c);
        for(int j = 0; j < c; j++) {
            int t;
            scanf("%d", &t);
            course[i].push_back(t-1);
        }
        idx[i] = i;
    }
    sort(idx, idx + n, Comp);
    vector<int> ls[K];
    for(int i = 0; i < n; i++) {
        int id = idx[i];
        for(int j=0;j<course[id].size();j++)
        	ls[course[id][j]].push_back(id);
    }
    for(int i=0; i<k; i++){
    	printf("%d %ld\n", i+1, ls[i].size());
    	for(int j=0; j<ls[i].size(); j++)
    		printf("%s\n", names[ls[i][j]].s);
    }
    return 0;
}