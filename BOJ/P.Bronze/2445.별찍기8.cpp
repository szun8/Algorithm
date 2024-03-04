#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int num = (n*2)-1;
    int star=1;
    while(num>0){
        int Rstar=n-star;
        for(int i=0;i<star;++i){
            cout<<"*";
        }
        for(int i=0;i<Rstar;++i){
            cout<<" ";
        }
        for(int i=0;i<Rstar;++i){
            cout<<" ";
        }
        for(int i=0;i<star;++i){
            cout<<"*";
        }
        if(num>n) star++;
        else star--;
        cout<<endl;
        num--;
    }
    return 0;
}