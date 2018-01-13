#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 20;
struct Node {
    int key;
    Node *lc, *rc;
    int h;
    Node(){
        h = -1;
        lc = rc = 0;
    }
	friend int Height(Node *n){
		return n ? n->h :(-1);
	}
};
struct AVLTree {
    Node nodes[N];
    int cnt = 0;
    AVLTree(){    	
    }
    Node *LL(Node *n){
        Node *l = n->lc;
        n->lc = l->rc;
        l->rc = n;
        n->h = max(Height(n->lc), Height(n->rc)) + 1;
        l->h = max(Height(l->lc), Height(l->rc)) + 1;
        return l;
    }
    Node *RR(Node *n){
    	Node *r = n->rc;
    	n->rc = r->lc;
    	r->lc = n;
    	n->h = max(Height(n->lc), Height(n->rc)) + 1;
    	r->h = max(Height(r->lc), Height(r->rc)) + 1;
    	return r;
    }
    Node *LR(Node *n){
    	n->lc = RR(n->lc);
    	return LL(n);
    }
    Node *RL(Node *n){
    	n->rc = LL(n->rc);
    	return RR(n);
    }
    Node *Insert(Node *n, int x){
    	// printf("%d\n", x);
    	if(n==0){
    		n = &nodes[cnt++];
    		n->key = x;
    	}else if(x < n->key){
    		n->lc = Insert(n->lc, x);
    		if(Height(n->lc) - Height(n->rc) == 2){
    			n = x < n->lc->key ? LL(n) : LR(n);
    		}
    	}else{
    		n->rc = Insert(n->rc, x);
    		if(Height(n->rc) - Height(n->lc) == 2){
    			n = x < n->rc->key ? RL(n) : RR(n);
    		}
    	}
    	n->h = max(Height(n->lc), Height(n->rc)) + 1;
    	return n;
    }
};
int n;
AVLTree tree;
int main(){
	scanf("%d", &n);
	Node *head = 0;
	for(int i=0;i<n;i++){
		int x;
		scanf("%d", &x);
		head = tree.Insert(head, x);
	}
	printf("%d\n", head->key);
    return 0;
}
