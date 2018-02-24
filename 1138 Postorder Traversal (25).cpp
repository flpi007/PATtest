#include <cstdio>

const int N = 50000;
int n;
int preorder[N], inorder[N];
int firstPost(int l, int r, int h){
    //preorder[h..]
    //inorder[l..x..r)
    int head = preorder[h];
    for(int x = l; x < r; x++){
        if(inorder[x] == head){
            if(l < x){
                return firstPost(l, x, h + 1);
            }else if(x + 1 < r){
                int lenL = x - l;
                return firstPost(x + 1, r, h + 1 + lenL);
            }else{
                return head;
            }
        }
    }
}
int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &preorder[i]);
    }
    for(int i=0; i<n; i++){
        scanf("%d", &inorder[i]);
    }
    printf("%d\n", firstPost(0, n, 0));
    return 0;
}