#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

const int N = 2000, M = 2000, DIM = 4;
const char COURSE[] = {'A', 'C', 'M', 'E'};
struct Stu {
    int rank[DIM];
    int id;
    Stu(int i): id(i) {};
    bool operator <(const Stu &rhs)
    {
        return id < rhs.id;
    }
    int getRank(char &c)
    {
        int r = rank[0];
        c = COURSE[0];
        for(int i = 1; i < DIM; i++) {
            if(rank[i] < r) {
                r = rank[i];
                c = COURSE[i];
            }
        }
        return r + 1;
    }
};
int n, m;
vector<Stu> students;
map<int, int> IdToSeq;
int grade[DIM][N];
int idx[N], selector;
bool Comp(int lid, int rid)
{
    return  grade[selector][lid] > grade[selector][rid];
}
int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) {
        int sid, c, m, e;
        scanf("%d%d%d%d", &sid, &c, &m, &e);
        grade[0][i] = (c + m + e) / 3;
        grade[1][i] = c;
        grade[2][i] = m;
        grade[3][i] = e;
        students.push_back(Stu(sid));
        IdToSeq[sid] = i;
        idx[i] = i;
    }
    for(selector = 0; selector < DIM; selector++) {
        sort(idx, idx + n, Comp);
        int cur, pre, rnk = 0;
        for(int i = 0; i < n; i++) {
            cur = idx[i];
            if(i == 0 || \
               grade[selector][cur] != grade[selector][pre]) {
                rnk = i;
            }
            students[cur].rank[selector] = rnk;
            pre = cur;
        }
    }
    for(int i = 0; i < m; i++) {
        int sid;
        scanf("%d", &sid);
        auto it = IdToSeq.find(sid);
        if(it != IdToSeq.end()) {
            int r; char c;
            r = students[it->second].getRank(c);
            // for(int k=0; k<DIM; k++){
            //     printf("%d, ", students[it->second].rank[k] + 1);
            // }
            printf("%d %c\n", r, c);
        } else {
            printf("N/A\n");
        }
    }
    return 0;
}