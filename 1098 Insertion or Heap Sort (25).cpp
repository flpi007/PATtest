#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int NINF = 0x80000000;
const int N = 100;
int a[N], b[N];
int n;
int isInsert()
{
    int j = n - 1;
    while(b[j] == a[j])
        j--;
    for(int i = 0; i < j; i++) {
        if(b[i] > b[i + 1])
            return 0;
    }
    return 1;
}
void InsertIt()
{
    int j = 0;
    for(; b[j] <= b[j+1]; j++);
    j++;
    for(int i = 0; i <= j; i++)
        if(b[i] > b[j]) {
            int t = b[j];
            for(int k = j; k >= i; k--) {
                b[k] = b[k - 1];
            }
            b[i] = t;
            return;
        }
}
void HeapIt()
{
    int j = n - 1;
    while(b[j] >= b[0])
        j--;
    swap(b[j], b[0]);
    int i = 0;
    while(i < j) {
        int ileft = 2 * i + 1, iright = 2 * i + 2;
        int left = (ileft < j) ? b[ileft] : NINF;
        int right = (iright < j) ? b[iright] : NINF;
        if(b[i] >= left && b[i] >= right) {
            return;
        } else if(left >= right) {
            swap(b[i], b[ileft]);
            i = ileft;
        } else {
            swap(b[i], b[iright]);
            i = iright;
        }
    }
}
int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for(int i = 0; i < n; i++)
        scanf("%d", &b[i]);
    if(!isInsert()) {
        printf("Heap Sort\n");
        HeapIt();
    } else {
        printf("Insertion Sort\n");
        InsertIt();
    }
    for(int i = 0; i < n; i++) {
        if(i) {
            printf(" ");
        }
        printf("%d", b[i]);
    }
    return 0;
}