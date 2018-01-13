#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <set>
using namespace std;

const int N = 10000;
int n, k;
map<string, int> rlist;
set<string> check;
bool isPrime(int x){
    for(int i=2; i * i < x; i++){
        if(x % i == 0){
            return false;
        }
    }
    return true;
}
int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        string name;
        cin >> name;
        rlist.insert(make_pair(name, i + 1));
    }
    cin >> k;
    for(int i=0; i<k; i++){
        string name;
        cin >> name;
        if(check.find(name) == check.end()){
            auto p = rli    st.find(name);
            if(p != rlist.end()){
                if(p->second == 1){
                    printf("%s: Mystery Award\n", name.c_str());
                }else if(isPrime(p->second)){
                    printf("%s: Minion\n", name.c_str());
                }else{
                    printf("%s: Chocolate\n", name.c_str());
                }
                check.insert(name);
            }else{
                printf("%s: Are you kidding?\n", name.c_str());
            }
        }else{
            printf("%s: Checked\n", name.c_str());
        }
    }
    return 0;
}