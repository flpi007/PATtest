#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int START = 28800, END = 61200;
struct Customer {
    int procTime, servTime, arrTime;
    Customer(int a, int p): arrTime(a), procTime(p) {
        servTime = 0;
    }
    bool operator <(const Customer &rhs) const
    {
        return arrTime < rhs.arrTime;
    }
};
struct Server {
    int freeTime;
    Server(int f): freeTime(f) {}
    bool operator <(const Server &rhs) const
    {
        return freeTime < rhs.freeTime;
    }
};
vector<Customer> customers;
vector<Server> servers;
int n, k;
int main()
{
    scanf("%d%d", &n, &k);
    for(int i = 0; i < k; i++) {
        servers.push_back(Server(START));
    }
    for(int i = 0; i < n; i++) {
        int hh, mm, ss, serv;
        scanf("%d:%d:%d %d", &hh, &mm, &ss, &serv);
        int t = hh * 60 * 60 + mm * 60 + ss;
        customers.push_back(Customer(t, serv * 60));
    }
    sort(customers.begin(), customers.end());
    int cnt = 0;
    long long sum = 0;
    for(auto it = customers.begin(); it != customers.end(); it++) {
        if(it->arrTime > END) break;
        sort(servers.begin(), servers.end());
        auto sit = servers.begin();
        int servT = max(sit->freeTime, it->arrTime);
        int freeT = min(servT + it->procTime, servT + 3600);
        it->servTime = servT;
        sit->freeTime = freeT;

        cnt++;
        sum += (servT - it->arrTime);
    }
    printf("%.1f\n", ((float) sum) / cnt / 60);
    return 0;
}