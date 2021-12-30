#include <iostream>
#include <sstream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--) {
        double num;
        cin>>num;
        string opers, oper;
        cin.ignore();
        getline(cin,opers);
        stringstream splitOper(opers);
        while(splitOper>>oper){
            if(oper=="@") num*=3;
            else if(oper=="%") num+=5;
            else if(oper=="#") num-=7;
        }
        cout<<fixed;
        cout.precision(2);
        cout<<num<<"\n";
    }
    return 0;
}