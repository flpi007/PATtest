#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;

int n, m, s;
vector<string> names;
int main()
{
    cin >> m >> n >> s;
    for(int i = 0; i < m; i++) {
        string name;
        cin >> name;
        names.push_back(name);
    }
    if(s > names.size()) {
        printf("Keep going...\n");
    } else {
        set<string> winners;
        for(int i = s - 1; i < names.size(); i += n) {
            while(i < names.size() && winners.find(names[i]) != winners.end()) {
                i++;
            }
            if(i < names.size()) {
                printf("%s\n", names[i].c_str());
                winners.insert(names[i]);
            }
        }
    }
    return 0;
}