#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 107, M = 8;
const int e2[M] = {
    1, 2, 4, 8, 16, 32, 64, 128
};
int n;
int a[N], b[N];
bool isInsert()
{
    int i;
    for(i = 1; b[i - 1] <= b[i] && i < n; i++);
    for(int j = i; j < n; j++) {
        if(b[j] != a[j]) {
            return false;
        }
    }
    return true;
}
void InsertIt()
{
    int i;
    for(i = 1; b[i - 1] <= b[i] && i < n - 1; i++);
    sort(b, b + i + 1);
}
void MergeIt()
{
    int l;
    bool isl = true;
    for(int i=1; i<M && isl; i++){
        l = e2[i];
        for(int f=0; f<n && isl;){
            int t = min(f + l, n);
            // printf("%d:%d\n", f, t);
            for(int j=f; j<t-1; j++){
                if(b[j] > b[j+1]){
                    isl = false;
                    break;
                }
            }
            f = t;
        }
    }
    for(int i = 0; i < n;){
        int j = min(i + l, n);
        sort(b + i, b + j);
        i = j;
    }
}
int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    if(isInsert()) {
        printf("Insertion Sort\n");
        InsertIt();
    } else {
        printf("Merge Sort\n");
        MergeIt();
    }
    for(int i = 0; i < n; i++) {
        if(i) {
            printf(" ");
        }
        printf("%d", b[i]);
    }
    printf("\n");
    return 0;
}