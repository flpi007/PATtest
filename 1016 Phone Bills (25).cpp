#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;

const int N = 1000, M = 21;
struct Record {
    int m, dd, hh, mm, isOn;
    Record(char *s1, char *s2)
    {
        sscanf(s1, "%d:%d:%d:%d", &m, &dd, &hh, &mm);
        if(s2[1] == 'n') {
            isOn = 1;
        } else {
            isOn = 0;
        }
    }
    int getT() const
    {
        return dd * 24 * 60 + hh * 60 + mm;
    }
    void printT(const char *s) const
    {
        printf("%02d:%02d:%02d%s", dd, hh, mm, s);
    }
    bool operator <(const Record &rhs) const
    {
        return m < rhs.m  || (m == rhs.m && getT() < rhs.getT());
    }
};
int toll[24];
int n;
set<Record> records[N];
map<string, int> nameToidx;
double getCost(const Record a)
{
    int h = a.dd * 24 + a.hh;
    int m = a.mm;
    int i;
    double sum = 0;
    for(i = 0; i < h; i++) {
        sum += toll[i % 24];
    }
    sum *= 60;
    sum += toll[i % 24] * m;
    return sum / 100;
}
int main()
{
    for(int i = 0; i < 24; i++) {
        scanf("%d", &toll[i]);
    }
    scanf("%d", &n);
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        char t1[M], t2[M], t3[M];
        scanf("%s%s%s", t1, t2, t3);
        // printf("%s %s %s\n", t1, t2, t3);
        string s(t1);
        auto it = nameToidx.find(s);
        if(it != nameToidx.end()) {
            records[it->second].insert(Record(t2, t3));
        } else {
            nameToidx[s] = cnt;
            records[cnt].insert(Record(t2, t3));
            cnt++;
        }
    }
    for(auto it = nameToidx.begin(); it != nameToidx.end(); it++) {
        set<Record> *r = &records[it->second];
        double total = 0;
        bool valid = false;
        for(auto i = r->begin(); i != r->end(); i++) {
            auto j = i; j++;
            if(i->isOn && j != r->end() && !j->isOn) {
                if(!valid) {
                    valid = true;
                    printf("%s %02d\n", it->first.c_str(), r->begin()->m);
                }
                i->printT(" "); j->printT(" ");
                int dt = j->getT() - i->getT();
                double fee = getCost(*j) - getCost(*i); total += fee;
                printf("%d $%.2f\n", dt, fee);
            }
        }
        if(valid) {
            printf("Total amount: $%.2f\n", total);
        }
    }
    return 0;
}