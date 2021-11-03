#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int star=n;
    int num=n;
    while(n>0){
        int Rstar=num-star;
        for(int i=0;i<Rstar;++i){
            cout<<" ";
        }
        for(int i=0;i<star;++i){
            cout<<"*";
        }
        for(int i=0;i<star-1;++i){
            cout<<"*";
        }
        star--;
        cout<<endl;
        n--;
    }
    return 0;
}