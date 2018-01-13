#include <cstdio>
#include <cstring>

const int N = 1000;
int n, mirror = 0, space = 0;
int a[N], lc[N], rc[N];
inline bool Comp(int i, int j)
{
    return (a[i] < a[j]) ^ mirror;
}
bool BuildTree(int front, int end)
{
    if(front >= end - 1 || front == -1) //1 leaf node or null
        return true;
    int middle = front + 1;
    for(; Comp(middle, front) && middle < end; middle++); //find split point
    for(int i=middle;i < end; i++) //validation
        if(Comp(i, front))
            return false;
    lc[front] = (middle > front + 1) ? front + 1 : -1;
    rc[front] = (middle < end) ? middle : -1;
    return BuildTree(lc[front], middle) && BuildTree(rc[front], end);
}
void PostTra(int p){
    if(p == -1)
        return;
    PostTra(lc[p]);
    PostTra(rc[p]);
    if(space)
        printf(" ");
    printf("%d", a[p]);
    space = 1;
}
int main()
{
    memset(a, 0, sizeof(a));
    memset(lc, -1, sizeof(lc));
    memset(rc, -1, sizeof(rc));
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    if(a[1] > a[0])
        mirror = 1;
    if(BuildTree(0, n)) {
        printf("YES\n");
        PostTra(0);
        printf("\n");
    } else {
        printf("NO\n");
    }
    return 0;
}