#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 100000;
int n, l, h;
struct Person {
    int id, virtue, talent, total, type;
    Person() {}
    Person(int i, int v, int t): id(i), virtue(v), talent(t)
    {
        total = virtue + talent;
        //sages, noblemen, foolmen, ?smallmen : 3..0
        if(virtue>=h && talent>=h)
            type = 3;
        else if(talent<h && virtue>=h)
            type = 2;
        else if(virtue<h && talent<h && virtue>=talent)
            type = 1;
        else
            type = 0;
    }
    bool operator <(const Person &rhs) const {
        if(type > rhs.type || (type == rhs.type && total > rhs.total) || \
            (type == rhs.type && total == rhs.total && virtue > rhs.virtue) || \
            (type == rhs.type && total == rhs.total && virtue == rhs.virtue && \
                id < rhs.id))
            return true;
        return false;
    }
};
vector<Person> person;
int main()
{
    scanf("%d%d%d", &n, &l, &h);
    for(int i=0;i<n;i++){
        int id, v, t;
        scanf("%d%d%d", &id, &v, &t);
        if(v>=l && t>=l){
            person.push_back(Person(id, v, t));
        }
    }
    sort(person.begin(), person.end());
    printf("%ld\n", person.size());
    for(int i=0;i<person.size();i++){
        printf("%08d %d %d\n", person[i].id, person[i].virtue, person[i].talent);
    }
    return 0;
}