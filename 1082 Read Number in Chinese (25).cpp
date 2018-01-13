#include <iostream>
using namespace std;

const char *UNIT[] = {
    "",
    "Shi",
    "Bai",
    "Qian",
    "Wan",
    "Yi",
};
const int Unit[] = {
    1,
    10,
    100,
    1000,
    10000,
    100000000,
};
const char *NUM[] = {
    "ling",
    "yi",
    "er",
    "san",
    "si",
    "wu",
    "liu",
    "qi",
    "ba",
    "jiu",
};
bool nfirst = false;
void print(int x, int u){
    if(nfirst){
        printf(" ");
    }else{
        nfirst = true;
    }
    printf("%s", NUM[x]);
    if(u != 0){
        printf(" %s", UNIT[u]);
    }
}
void printQian(int x, int stat){
    int a[5];
    a[4] = x / Unit[4]; x = x % Unit[4];
    for(int i=3; i >=0; i--){
        a[i] = x / Unit[i]; x = x % Unit[i];
        if(stat && a[i+1] == 0 && a[i]){
            print(0, 0);
        }
        if(a[i] > 0){
            print(a[i], i);
            stat = 1;
        }
    }
}
int main(){
    int a;
    cin >> a;
    if(a < 0){
        a = -a;
        printf("Fu ");
    }
    if(a == 0){
        printf("ling\n");
    }else{        
        int yi = a / Unit[5]; a = a % Unit[5];
        int wan = a / Unit[4]; a = a % Unit[4];
        if(yi > 0){
            print(yi, 5);
        }
        if(wan > 0){
            printQian(wan + yi * Unit[4], yi);
            printf(" %s", UNIT[4]);
        }
        printQian(a + (wan % 10) * Unit[4], wan || yi);
        printf("\n");
    }
    return 0;
}