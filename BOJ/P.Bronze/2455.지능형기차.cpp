#include <iostream>
using namespace std;
int main(){
    int count = 0;
    int max = 0;
    for(int i=0;i<4;i++){
        int a,b;
        cin>>a>>b;
        count-=a;// 하차수
        count+=b;// 승차수
        if(count > max) max=count;
    }
    cout<<max;
    return 0;
}