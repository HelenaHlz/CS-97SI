#include <iostream>
#include <string>
using namespace std;

/*
 * 题目意思有点难懂 参看https://blog.csdn.net/weixin_30354675/article/details/99128197
 * 模拟耗油
 */
int main(){
    int scenario;
    cin>>scenario;
    for(int i=1;i<=scenario;i++){
        cout<<"Scenario #"<<i<<":"<<endl;
        int oil;
        cin>>oil;
        for(int j=1;j<=2*oil+1;j++){
            cout<<"slice #"<<j<<":"<<endl;
            int center_value = abs(oil+1-j);
            int left_oil=oil-center_value;
            for(int n=0;n<2*oil+1;n++){
                for(int m=0;m<2*oil+1;m++){
                    if(abs(n-oil)+abs(m-oil)>left_oil){
                        cout<<".";
                    } else{
                        cout<<abs(n-oil)+abs(m-oil)+center_value;
                    }
                }
                cout<<endl;
            }
        }
        cout<<endl;//presentation error
    }
    return 0;
}