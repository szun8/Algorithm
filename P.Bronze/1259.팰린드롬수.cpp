#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    string num;
    while(true){
        cin >> num;
        if(num=="0") return 0;
        
        string Rnum = num;
        reverse(num.begin(),num.end());
        if(num==Rnum){
            cout<<"yes"<<endl;
        }
        else cout<<"no"<<endl; 
    }
    return 0;
}