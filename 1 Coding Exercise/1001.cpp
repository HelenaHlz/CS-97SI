#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
 * 用快速幂不然会TLE
 * https://www.jianshu.com/p/acb85787af4e
 * https://blog.csdn.net/kenden23/article/details/23997827
 * http://poj.org/showmessage?message_id=76017
 **/

string erase_zero(string s){
    bool has_pot=false;
    if(s.find(".")!=-1){
        has_pot= true;
    }
    s.erase(0,s.find_first_not_of("0"));
    if(has_pot){
        s.erase(s.find_last_not_of("0")+1);
    }
    return s;
}

string multiply(string str1,string str2){
    int dot1=0;
    for(int i=str1.size()-1;i>=0;i--){
        if(str1[i]=='.'){
            dot1=str1.size()-i-1;
            str1.erase(str1.find("."),1);
            break;
        }
    }
    int dot2=0;
    for(int i=str2.size()-1;i>=0;i--){
        if(str2[i]=='.'){
            dot2=str2.size()-i-1;
            str2.erase(str2.find("."),1);
            break;
        }
    }
    int len1=str1.size();
    int len2=str2.size();
    vector<int> tmp(len1+len2,0);
    for(int i=len1-1;i>=0;i--){
        for(int j=len2-1;j>=0;j--){
            tmp[i+j+1] += (str1[i]-'0')*(str2[j]-'0');
        }
    }
    int carry=0;
    for(int i=len1+len2-1;i>=0;i--){
        int n_carry;
        n_carry=(tmp[i]+carry)/10;
        tmp[i]=(tmp[i]+carry)%10;
        carry=n_carry;
    }
    string rst="";
    for(int i=len1+len2-1;i>=0;i--){
        if((dot1!=0 || dot2!=0) && len1+len2-1-i==dot1+dot2){
            rst="."+rst;
        }
        rst=char(tmp[i]+'0')+rst;
    }
    if((dot1!=0 || dot2!=0)&&(dot1+dot2==len1+len2))
    {
        rst="."+rst;
    }
    rst=erase_zero(rst);
    return rst;
}

//快速幂
string expo(string multipler, int time){
    if(time==1) return multipler;
    string res="1",base=multipler;
    while(time!=0){
        if(time&1) res=multiply(res,base);
        base= multiply(base,base);// 5^7=5^1*5^2*5^4 (7)2=111
        time>>1;
    }
    return res;
}


int main(){
    string s;
    int n;
    while(cin>>s>>n){
        if(n==0){
            cout<<"1"<<endl;
        }else if(n==1){
            s=erase_zero(s);
            if(s.find(".")==s.size()-1){
                s.erase(s.size()-1);
            }
            if(s=="."||s==""){
                cout<<"0"<<endl;
            }else{
                cout<<s<<endl;
            }
        }else{
            s=erase_zero(s);
            string rst=expo(s,n);
            cout<<rst<<endl;
        }
    }
    return 0;
}