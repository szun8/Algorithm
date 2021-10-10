#include <iostream>
using namespace std;

int main(){
    int input;
    cin >> input;

    for(int i =0;i<input;++i){
        int a,b;
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cin>>a;
        cin>>b;
        cout<<a+b<<"\n";
        
    }
    return 0;
}