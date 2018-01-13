#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int v = 0)
    {
        val = v;
        left = right = 0;
    }
};
int n;
vector<int> preorder, inorder;
Node *buildTree(int front, int tail, int p)
{
    if(front >= tail) {
        return 0;
    }
    int parent = preorder[p];
    // pre: a <b> <c>
    // in : <b> a <c>
    for(int i = front; i < tail; i++) {
        if(inorder[i] == parent) {
            Node *u = new Node(parent);
            u->left = buildTree(front, i, p + 1);
            u->right = buildTree(i + 1, tail, p + (i - front) + 1);
            return u;
        }
    }
    return 0;
}
void postOrder(Node *u)
{
    if(u == 0) {
        return;
    }
    postOrder(u->left);
    postOrder(u->right);
    printf("%d ", u->val);
}
int main()
{
    cin >> n;
    stack<int> s;
    for(int i = 0; i < 2 * n; i++) {
        string op;
        cin >> op;
        if(op == "Push") {
            int val;
            cin >> val;
            preorder.push_back(val);
            s.push(val);
        } else if(op == "Pop") {
            int v = s.top(); s.pop();
            inorder.push_back(v);
        }
    }
    Node *root = buildTree(0, n, 0);
    postOrder(root->left);
    postOrder(root->right);
    printf("%d\n", root->val);
    return 0;
}