#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 10000, K = 80000, L = 8;
int n, k;
char name[N][L];
int t[N], q[K], isIn[N];
int idx[N];
int intTime(char *s)
{
    int t = 0;
    for(int i = 0; i < 3; i++) {
        int a;
        a = (s[0] - '0') * 10 + (s[1] - '0');
        s += 3;
        t = t * 60 + a;
    }
    return t;
}
void PrintTime(int t)
{
    int a[3];
    for(int i = 0; i < 3; i++) {
        a[i] = t % 60;
        t = t / 60;
    }
    printf("%.2d:%.2d:%.2d", a[2], a[1], a[0]);
}
bool Comp(int a, int b)
{
    int x = memcmp(name[a], name[b], L);
    if(x < 0) return true;
    else if(x > 0) return false;
    return t[a] < t[b];
}
int main()
{
    scanf("%d %d\n", &n, &k);
    char st[10], si[10];
    for(int i = 0; i < n; i++) {
        scanf("%s %s %s\n", name[i], st, si);
        t[i] = intTime(st);
        isIn[i] = si[0] == 'i' ? 1 : 0;
        idx[i] = i;
    }
    for(int i = 0; i < k; i++) {
        scanf("%s\n", st);
        q[i] = intTime(st);
    }
    sort(idx, idx + n, Comp);

    int cnt[24 * 60 * 60], span[N], carID[N], nCar = 0;
    memset(cnt, 0, sizeof(cnt));
    memset(span, 0, sizeof(span));
    int pre = idx[0];
    int in = -1;
    carID[0] = idx[0];
    for(int i = 0; i < n; i++) {
        int id = idx[i];
        if(memcmp(name[pre], name[id], L) == 0) {
            if(isIn[id]) //update in
                in = t[id];
            else {
                if(in == -1) continue; //match out
                span[nCar] += t[id] - in;
                cnt[t[id]]--;
                cnt[in]++;
                in = -1;
            };
        } else {
            carID[++nCar] = id;
            pre = id;
            in = isIn[id] ? t[id] : -1;
        }
    }
    int sum = 0;
    for(int i = 0; i < 24 * 60 * 60; i++) {
        sum += cnt[i];
        cnt[i] = sum;
    }
    for(int i = 0; i < k; i++)
        printf("%d\n", cnt[q[i]]);
    vector<int> maxN;
    int maxSpan = 0;
    for(int i=0;i<=nCar;i++){
        if(span[i]>maxSpan){
            maxSpan=span[i];
            maxN.clear();
            maxN.push_back(carID[i]);
        }else if(span[i]==maxSpan){
            maxN.push_back(carID[i]);
        }
    }
    for(int i=0;i<maxN.size();i++)
        printf("%s ", name[maxN[i]]);
    PrintTime(maxSpan);
    return 0;
}