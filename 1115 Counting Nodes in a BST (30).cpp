#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1007;
struct Node {
    Node *left, *right;
    int value;
    Node(int v)
    {
        left = right = 0;
        value = v;
    }
};

int n, maxd;
int cnt[2];
Node *root;
void insertN(Node *u, int t)
{
    if(t <= u->value) {
        if(u->left) {
            insertN(u->left, t);
        } else {
            u->left = new Node(t);
        }
    } else {
        if(u->right) {
            insertN(u->right, t);
        } else {
            u->right = new Node(t);
        }
    }
}
int ddfs(Node *u)
{
    if(!u) {
        return 0;
    } else {
        return max(ddfs(u->left), ddfs(u->right)) + 1;
    }
}
void dfs(Node *u, int d)
{
    if(!u) {
        return;
    } else {
        if(d == maxd) {
            cnt[0]++;
        } else if(d + 1 == maxd) {
            cnt[1]++;
        }
        dfs(u->left, d + 1);
        dfs(u->right, d + 1);
    }
}
int main()
{
    scanf("%d", &n);
    int t;
    scanf("%d", &t);
    root = new Node(t);
    for(int i = 1; i < n; i++) {
        scanf("%d", &t);
        insertN(root, t);
    }
    maxd = ddfs(root);
    dfs(root, 1);
    printf("%d + %d = %d\n", cnt[0], cnt[1], cnt[0] + cnt[1]);
    return 0;
}