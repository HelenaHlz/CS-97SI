#include <stdio.h>
#include <cmath>
#define MIN_VALUE 1e-8
#define IS_DOUBLE_ZERO(d)(abs(d)<MIN_VALUE)

int main(){
    double n;
    scanf("%lf",&n);
    while (!IS_DOUBLE_ZERO(n)){
        int num=2;
        double sum= 1.0/num;//int除法注意
        while(sum<=n){
            num+=1;
            sum+=(1.0/num);
        }
        printf("%d card(s)\n",num-1);
        scanf("%lf",&n);
    }
    return 0;
}