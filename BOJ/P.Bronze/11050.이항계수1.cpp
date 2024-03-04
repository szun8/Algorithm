#include <iostream>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    int nMk = n-k;
    int on=1, off=1;
    for(int i =n;i>0;i--){
        on*=i;
    }
    for(int i =k;i>0;i--){
        off*=i;
    }
    for(int i =nMk;i>0;i--){
        off*=i;
    }
    int result = on/off;
    cout<<result;
    return 0;
}