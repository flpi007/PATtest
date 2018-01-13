#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int AGE = 207, M = 9;
struct People {
    char name[M];
    int age, worth;
    People(char *nn, int aa, int ww)
    {
        memcpy(name, nn, sizeof(name));
        age = aa;
        worth = ww;
    }
    bool operator <(const People &rhs) const
    {
        return (worth > rhs.worth) \
               || (worth == rhs.worth && age < rhs.age)
               || (worth == rhs.worth \
                   && age == rhs.age && \
                   strcmp(name, rhs.name) < 0);
    }
};
int n, k;
vector<People> peoples;
int main()
{
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        char name[M];
        int age, worth;
        scanf("%s%d%d\n", name, &age, &worth);
        peoples.push_back(People(name, age, worth));
    }
    sort(peoples.begin(), peoples.end());
    for(int i = 0; i < k; i++) {
        printf("Case #%d:\n", i + 1);
        int m, amin, amax, cnt = 0;
        cin >> m >> amin >> amax;
        for(int j = 0; j < peoples.size() && cnt < m; j++) {
            if(peoples[j].age >= amin && peoples[j].age <= amax) {
                People &p = peoples[j];
                printf("%s %d %d\n", p.name, p.age, p.worth);
                cnt++;
            }
        }
        if(cnt == 0) {
            printf("None\n");
        }
    }
    return 0;
}