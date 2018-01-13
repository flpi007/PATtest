#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int val, h;
    Node *left, *right, *parent;
    Node(int v = 0)
    {
        val = v;
        left = right = parent = 0;
        h = 0;
    }
};
struct AVLTree {
    Node *head;
    int nodeCnt = 0;
    AVLTree()
    {
        head = new Node();
    }
    Node *root()
    {
        return head->parent;
    }
    int height(Node *u)
    {
        return (u) ? u->h : -1;
    }
    void updateH(Node *u)
    {
        u->h = max(height(u->left), height(u->right)) + 1;
    }
    void relink(Node *p, Node *s, int dir)
    {
        // printf("relink:%d->%d\n", p ? p->val : -1, s ? s->val : -1);
        if(p == head) {
            p->parent = s;
        } else if(p) {
            if(dir) {
                p->left = s;
            } else {
                p->right = s;
            }
        }
        if(s) {
            s->parent = p;
        }
    }
    Node *rotate_left(Node *u)
    {
        // printf("rot l:%d\n", u->val);
        Node *p = u->parent;
        Node *r = u->right;
        relink(p, r, (u == p->left));
        relink(u, r->left, 0);
        relink(r, u, 1);
        updateH(u);
        updateH(r);
        updateH(p);
        return r;
    }
    Node *rotate_right(Node *u)
    {
        // printf("rot r:%d\n", u->val);
        Node *p = u->parent;
        Node *l = u->left;
        relink(p, l, (u == p->left));
        relink(u, l->right, 1);
        relink(l, u, 0);
        updateH(u);
        updateH(l);
        updateH(p);
        return l;
    }
    void rebalance(Node *x)
    {
        Node *y = x->parent;
        updateH(y);
        while(x != root() && x != head) {
            if(height(y->left) - height(y->right) > 1) {
                if(height(x->right) > height(x->left)) {
                    rotate_left(x);
                    rotate_right(y);
                } else {
                    rotate_right(y);
                }
                break;
            } else if(height(y->right) - height(y->left) > 1) {
                if(height(x->left) > height(x->right)) {
                    rotate_right(x);
                    rotate_left(y);
                } else {
                    rotate_left(y);
                }
                break;
            } else if(height(y->right) - height(y->left) == 0) {
                break;
            } else {
                x = y;
                y = y->parent;
                updateH(y);
            }
        }
    }
    Node *__insert(Node *y, int v)
    {
        // printf("ins:%d\n", v);
        Node *z = new Node(v);
        if(y == head) {
            y->parent = z;
        } else if(v <= y->val) {
            y->left = z;
        } else if(v > y->val) {
            y->right = z;
        }
        z->parent = y;
        nodeCnt++;
        updateH(y);
        rebalance(y);
        return z;
    }
    Node *insertV(int v)
    {
        Node *y = head;
        Node *x = root();
        while(x != 0) {
            y = x;
            x = (v <= x->val) ? x->left : x->right;
        }
        return __insert(y, v);
    }
};
AVLTree avltree;
int n;
bool iscomplete(Node *u)
{

}
int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        // printf("%d\n", i);
        int t;
        scanf("%d", &t);
        avltree.insertV(t);
    }
    bool first = true;
    queue<Node *> q;
    queue<int> idq;
    vector<int> lo;
    q.push(avltree.root());
    idq.push(0);
    while(!q.empty()) {
        Node *u = q.front(); q.pop();
        int idu = idq.front(); idq.pop();
        lo.push_back(idu);
        if(!first) {
            printf(" ");
        } else {
            first = false;
        }
        printf("%d", u->val);
        if(u->left) {
            q.push(u->left);
            idq.push(idu * 2 + 1);
        }
        if(u->right) {
            q.push(u->right);
            idq.push(idu * 2 + 2);
        }
    }
    printf("\n");
    bool complete = true;
    for(int i=0; i<lo.size(); i++){
        if(lo[i] != i){
            complete = false;
            break;
        }
    }
    if(complete) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}