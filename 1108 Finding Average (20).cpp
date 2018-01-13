#include <cstdio>
#include <cctype>

int n, cnt;
double sum;
bool check(char *s, double *x){
    char *str, *sp;
    int point = 0;
    for(str = s; *str; str++){
        if(*str == '.'){
            if(!point){
                point = 1;
                sp = str + 1;
            }else{
                return false;
            }
        }else if(*str != '-' && !isdigit(*str)){
            return false;
        }
    }
    if(point && *sp && *(sp + 1) && *(sp + 2)){
        return false;
    }
    sscanf(s, "%lf", x);
    return true;
}
int main(){
    cnt = 0;
    sum = 0;
    scanf("%d\n", &n);
    for(int i=0; i<n; i++){
        char str[1024];
        scanf("%s", str);
        double x;
        if(check(str, &x) && x <= 1000.00 && x >= -1000.00){
            sum += x;
            cnt++;
        }else{
            printf("ERROR: %s is not a legal number\n", str);
        }
    }
    if(cnt <= 0){
        printf("The average of 0 numbers is Undefined\n");
    }else if(cnt == 1){
        printf("The average of 1 number is %.2lf\n", sum);
    }else{
        printf("The average of %d numbers is %.2lf\n", cnt, sum / cnt);
    }
    return 0;
}