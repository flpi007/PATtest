#include <cstdio>

const int N = 3;
const char RESULT[] = {'W', 'T', 'L'};
float M[N][N];
float getMax(int i, int &x){
    x = 0;
    float max = M[i][0];
    for(int j=1; j<N; j++){
        if(M[i][j] > max){
            max = M[i][j];
            x = j;
        }
    }
    return max;
}
int main(){
    float product = 1.0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%f", &M[i][j]);
        }
        int t;
        product *= getMax(i, t);
        printf("%c ", RESULT[t]);
    }
    printf("%.2f\n", (product * 0.65 - 1.0) * 2.0);
}