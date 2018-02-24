#include <cstdio>
#include <cmath>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 25;
struct Stu {
    string name;
    union {
        struct {
            int Gp, Gmid, Gfinal, G;
        };
        int data[4];
    };
    Stu()
    {
        Gp = Gmid = Gfinal = G = -1;
    }
};
int p, m, n;
map<string, int> nameToidx;
vector<Stu> students;
void read(int x, int selector)
{
    for(int i = 0; i < x; i++) {
        char s[N];
        int grade;
        scanf("%s%d", s, &grade);
        string name(s);
        if(nameToidx.find(name) != nameToidx.end()) {
            int idx = nameToidx[name];
            students[idx].data[selector] = grade;
        } else {
            students.push_back(Stu());
            students.rbegin()->name = name;
            students.rbegin()->data[selector] = grade;
            nameToidx[name] = students.size() - 1;
        }
    }
}
bool Cmp(int i, int j)
{
    const Stu &a = students[i], &b = students[j];
    return a.G > b.G || (a.G == b.G && a.name < b.name);
}
int main()
{
    scanf("%d%d%d", &p, &m, &n);
    read(p, 0);
    read(m, 1);
    read(n, 2);
    vector<int> idx;
    for(int i = 0; i < students.size(); i++) {
        Stu &stu = students[i];
        if(stu.Gp >= 200) {
            if(stu.Gmid > stu.Gfinal) {
                stu.G = int(stu.Gmid * 0.4 + stu.Gfinal * 0.6 + 0.5);
            } else {
                stu.G = stu.Gfinal;
            }
            if(stu.G >= 60) {
                idx.push_back(i);
            }
        }
    }
    sort(idx.begin(), idx.end(), Cmp);
    for(int i = 0; i < idx.size(); i++) {
        Stu &stu = students[idx[i]];
        printf("%s %d %d %d %d\n", stu.name.c_str(), stu.Gp, \
               stu.Gmid, stu.Gfinal, stu.G);
    }
    return 0;
}