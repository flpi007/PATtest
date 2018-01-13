#include <iostream>
#include <cstring>
using namespace std;

const int N = 1000;
int k, n;
int main()
{
    cin >> k;
    for(int i = 0; i < k; i++) {
        cin >> n;
        int vis[N][N], r;
        bool valid = true;
        memset(vis, 0, sizeof(vis));
        for(int j = 0; j < n; j++) {
            cin >> r;
            r--;
            if(valid && !vis[j][r]) {
                vis[j][r] = 1;
                for(int k = 0; k < n; k++) {
                    vis[k][r] = 1;
                    //NE dir: y-x==c: r-j=c=y-x
                    if(k + r - j < n && k + r - j >= 0)
                        vis[k][r - j + k] = 1;
                    //SE dir: y+x==c: r+j=c=y+x
                    if(r + j - k < n && r + j - k >= 0)
                        vis[k][r + j - k] = 1;
                }
            } else {
                valid = false;
            }
        }
        if(valid){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}