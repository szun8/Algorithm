#include <iostream>
using namespace std;

int main(){
    int k,m,n;
    cin>>k>>n>>m;
    if(((k*n)-m)<=0) cout<<0;
    else cout<<(k*n)-m;
    return 0;
}