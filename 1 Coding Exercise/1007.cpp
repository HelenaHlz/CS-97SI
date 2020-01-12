#include <iostream>
#include <algorithm>
char str_arr[100][50];
int unsorted_arr[100];

struct DNA{
    char dna[51];
    int unsorted_num;
}dna_arr[101];//struct的定义

/*
 * 返回true a比b小 按升序排列 a在b前面
 */
bool cmp(DNA a,DNA b){
    return a.unsorted_num<b.unsorted_num;
}


int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%s",dna_arr[i].dna);
        int c=0,g=0,t=0;
        for(int j=0;j<n;j++){
            if(dna_arr[i].dna[j]=='A'){
                dna_arr[i].unsorted_num+=(c+g+t);
            }
            if(dna_arr[i].dna[j]=='C') {
                dna_arr[i].unsorted_num+=(g+t);
                c++;
            }
            if(dna_arr[i].dna[j]=='G'){
                dna_arr[i].unsorted_num+=t;
                g++;
            }
            if(dna_arr[i].dna[j]=='T'){
                t++;
            }
        }
    }
    /*
     * Sorts the elements in the range [first, last) in ascending order.The order of equal elements is not guaranteed to be preserved.
     * A sequence is sorted with respect to a comparator comp if for any iterator it pointing to the sequence and any non-negative integer n such that it + n is a valid iterator pointing to an element of the sequence
     * returns ​true if the first argument is less than (i.e. is ordered before) the second.
     * true if the first argument of the call appears before the second in the strict weak ordering relation induced by this type, and
     * https://en.cppreference.com/w/cpp/algorithm/sort
     *
     */
    std::sort(dna_arr,dna_arr+m,cmp);
    for(int i=0;i<m;i++){
        printf("%s\n",dna_arr[i].dna);
    }
    return 0;
}