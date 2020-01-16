#include <iostream>
#include <cmath>
using namespace std;
const int INF=0x3f3f3f3f;

//最值

int main(){
    int n;
    double distance=4.5*3600;
    while(cin>>n&&n!=0){
        int min=INF;
        for(int i=0;i<n;i++){
            int speed,setoff;
            cin>>speed>>setoff;
            if(setoff>=0){
                int arrive= ceil(distance/speed)+setoff;
                if(min>arrive){
                    min=arrive;
                }
            }
        }
        cout<<min<<endl;
    }
    return 0;
}