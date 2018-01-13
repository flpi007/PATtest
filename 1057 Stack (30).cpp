#include <cstdio>
#include <set>
#include <stack>
using namespace std;
const int N = 100005;

stack<int> s;
multiset<int> s1, s2; // 0 <= s1 - s2 <= 1
int n;
void Add(int x)
{
    s.push(x);
    if(s1.size() == s2.size()) {
        s2.insert(x);
        s1.insert(*s2.begin());
        s2.erase(s2.begin());
    } else {
        s1.insert(x);
        s2.insert(*s1.rbegin());
        s1.erase(s1.find(*s1.rbegin()));
    }
}
void Pop(){
    int x = s.top(); s.pop();
    printf("%d\n", x);
    multiset<int>::iterator i1=s1.find(x), i2=s2.find(x);
    if(s1.size() == s2.size()){
        if(i2!=s2.end()){
            s2.erase(i2);
            return;
        }
        s1.erase(i1);
        s1.insert(*s2.begin());
        s2.erase(s2.begin());
    }else{
        if(i1!=s1.end()){
            s1.erase(i1);
            return;
        }
        s2.erase(i2);
        s2.insert(*s1.rbegin());
        s1.erase(s1.find(*s1.rbegin()));
    }
}
void Median(){
    printf("%d\n", *s1.rbegin());
}
int main()
{
    scanf("%d\n", &n);
    char str[50];
    for(int i = 0; i < n; i++) {
        scanf("%s", str);
        int a;
        if(str[1] == 'u') { //push
            scanf("%d\n", &a);
            Add(a);
            continue;
        }
        if(s.size() == 0) {
            printf("Invalid\n");
            continue;
        }
        switch(str[1]) {
        case 'o': Pop(); break;
        case 'e': Median(); break;
        }
    }
    return 0;
}