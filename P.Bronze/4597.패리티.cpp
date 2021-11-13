#include <iostream>
using namespace std;
int main(){
    string parity;
    while(true){
        cin>>parity;
        
        if(parity=="#") return 0;
        else{
            int count=0;
            for(int i=0;i<parity.size()-1;i++){
                if(parity[i]=='1') count++;
            }
            if(parity.back()=='e'){
                //짝수 패리티
                if(count%2==0) parity.back()='0';
                else parity.back()='1';
            }
            else if(parity.back()=='o'){
                //홀수 패리티
                if(count%2==1) parity.back()='0';
                else parity.back()='1';
            }

            cout<<parity<<endl;
        }
    }
}