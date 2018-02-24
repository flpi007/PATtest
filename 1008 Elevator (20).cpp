#include <cstdio>

const int Up = 6, Down = 4, Stop = 5;
int n;
int main(){
    scanf("%d", &n);
    int x = 0, sum = 0, t;
    for(int i=0; i<n; i++){
        scanf("%d", &t);
        if(t - x > 0){
            sum += Up * (t - x) + Stop;
        }else{
            sum += Down * (x - t) + Stop;
        }
        x = t;
    }
    printf("%d\n", sum);
    return 0;
}