#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int num=n*2;
    int rst=1;
    for(int i=2;i<=n;i++){
        if(num%i==0){
            if(num/i+1-i>0 && (num/i+1-i)%2==0){
                rst++;
            }
        }
    }
    printf("%d",rst);
    return 0;
}