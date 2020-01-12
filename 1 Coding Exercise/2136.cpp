#include <iostream>
#include <vector>
#include <string>
//clion不加这一行也能编译通过，但是pkuoj上面过不去

using namespace std;

int main(){

    vector<int> cnt_arr(26,0);
    int max=0;
    int max_ch=0;

    for(int i=0;i<4;i++){
        string str1;
        getline(cin,str1);
        for(string::iterator it=str1.begin();it!=str1.end();it++) {
            if (*it >= 'A' and *it <= 'Z') {
                cnt_arr[*it - 'A']++;
            }
        }
    }
    for(int i=0;i<26;i++){
        if(cnt_arr[i]>=max){
            max=cnt_arr[i];
            max_ch=i;
        }
    }
    //主要是输出很恶心，star记一下每行结尾到哪个字母
    vector<int> star(max,max_ch);
    for(int j=0;j<max;j++){
        for(int i=max_ch;i<26;i++){
            if(cnt_arr[i]>j){
                star[j]=i;
            }
        }
    }

    for(int i=max-1;i>=0;i--){
        for(int j=0;j<star[i];j++){
            if(cnt_arr[j]>i){
                cout<<"* ";
            } else{
                cout<<"  ";
            }
        }
        if(cnt_arr[star[i]]>0){
            cout<<"*";
        }
        cout<<endl;
    }
    //输出字母行
    for(int i=0;i<25;i++){
        cout<<char('A'+i)<<" ";
    }
    cout<<'Z';
    return 0;
}