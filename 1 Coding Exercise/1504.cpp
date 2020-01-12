#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        int a,b;
        scanf("%d%d",&a,&b);
        int a1=0,b1=0;
        while(a>0){
            a1=a1*10+a%10;
            a/=10;
        }
        while(b>0){
            b1=b1*10+b%10;
            b/=10;
        }
        int c=a1+b1;
        int rst=0;
        while(c>0){
            rst=rst*10+c%10;
            c/=10;
        }
        printf("%d\n",rst);
    }
    return 0;
}