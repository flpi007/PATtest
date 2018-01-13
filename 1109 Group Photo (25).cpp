#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

const int N = 10000, K = 10;
struct Stu {
    string name;
    int height;
    Stu(string n, int h)
    {
        name = string(n);
        height = int(h);
    }
    bool operator <(const Stu &rhs) const
    {
        return (height < rhs.height || (height == rhs.height && name > rhs.name));
    }
};
int n, k;
vector<Stu> stus;
deque<int> lines[K];
int main()
{
    cin >> n;
    cin >> k;
    for(int i = 0; i < n; i++) {
        string str;
        int h;
        cin >> str;
        cin >> h;
        stus.push_back(Stu(str, h));
    }
    sort(stus.begin(), stus.end());
    int m = n / k;
    int cnt = 0;
    for(int i = 0; i < k - 1; i++) {
        lines[i].push_back(cnt + m - 1);
        int left = 1;
        for(int j = 1; j < m; j++) {
            int id = cnt + m - 1 - j;
            if(left) {
                lines[i].push_front(id);
            } else {
                lines[i].push_back(id);
            }
            left = !left;
        }
        cnt = cnt + m;
    }
    lines[k - 1].push_back(n - 1);
    int left = 1;
    for(int j = n - 2; j >= cnt; j--) {
        int id = j;
        if(left) {
            lines[k - 1].push_front(id);
        } else {
            lines[k - 1].push_back(id);
        }
        left = !left;
    }
    for(int i = k - 1; i >= 0; i--) {
        for(int j = 0; j < lines[i].size(); j++) {
            if(j)
                printf(" ");
            int id = lines[i][j];
            printf("%s", stus[id].name.c_str());
        }
        printf("\n");
    }
    return 0;
}