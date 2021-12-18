#include <iostream>
using namespace std;
int main(){
    long long a,b;
    cin>>a>>b;
    if(a<0 && b>0) {
        a*=-1;
        cout<<a+b;
    }
    else if(a>0 && b<0) {
        b*=-1;
        cout<<a+b;
    }
    else if(a>=0 && b>=0 || a<=0 && b<=0){
        a>b ? cout<<a-b : cout<<b-a;
    }
    else if(a==b) cout<<"0";
    return 0;
}