#include <iostream>
using namespace std;

int main(){
    int input;
    cin >> input;
    while(input>0){
        for(int j=input;j>0;--j){
            cout<<"*";
        }
        cout<<endl;
        input--;
    }
    return 0;
}