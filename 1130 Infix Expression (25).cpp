#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int N = 27;
struct Node {
    string str;
    int left, right;
    Node(string &s, int l = -1, int r = -1)
    {
        str = s;
        left = l;
        right = r;
    }
};
int n, root, vis[N];
vector<Node> nodes;
string inorder(int u)
{
    if(u == -1) {
        return "";
    }
    string left = inorder(nodes[u].left);
    string right = inorder(nodes[u].right);
    if(left == "" && right == "") {
        return nodes[u].str;
    } else if(u == root) {
        return left + nodes[u].str + right;
    } else {
        return "(" + left + nodes[u].str + right + ")";
    }
}
int main()
{
    cin >> n;
    for(int i = 0; i < n; i++) {
        string s;
        int l, r;
        cin >> s >> l >> r;
        if(~l)
            vis[--l] = 1;
        if(~r)
            vis[--r] = 1;
        nodes.push_back(Node(s, l, r));
    }
    root = -1;
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            root = i;
            break;
        }
    }
    string out = inorder(root);
    printf("%s\n", out.c_str());
    return 0;
}