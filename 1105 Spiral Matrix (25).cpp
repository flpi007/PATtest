#include <cstdio>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
vector<int> a;
vector<vector<int>> d; //matrix[m][n]
int n, m, N;
int main()
{
    scanf("%d", &N);
    a.reserve(N);
    for(int i = 0; i < N; i++) {
        int t;
        scanf("%d", &t);
        a.push_back(t);
    }
    sort(a.begin(), a.end(), greater<int>());
    for(int i = N; i > 0 && i * i >= N; i--) {
        if(N % i == 0) {
            m = i;
        }
    }
    n = N / m;
    d.resize(m);
    for(int i = 0; i < m; i++) {
        d[i].resize(n);
    }
    int x = 0, y = 0, cnt = 1;
    for(int dir = 0; ; dir = (dir + 1) % 4) {
        if(x < 0 || x >= m || y < 0 || y >= n || d[x][y] != 0) {
            break;
        } else {
            int nx = x, ny = y;
            for(; nx >= 0 && ny >= 0 && nx < m && ny < n && d[nx][ny] == 0;) {
                x = nx; y = ny;
                d[x][y] = cnt++;
                nx += dx[dir];
                ny += dy[dir];
            }
            x += dx[(dir + 1) % 4];
            y += dy[(dir + 1) % 4];
        }
    }
    for(int i = 0; i < d.size(); i++) {
        for(int j = 0; j < d[i].size(); j++) {
            if(j)
                printf(" ");
            int v = d[i][j] - 1;
            printf("%d", a[v]);
        }
        printf("\n");
    }
    return 0;
}