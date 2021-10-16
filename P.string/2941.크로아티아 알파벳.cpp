#include<iostream>
using namespace std;

int main(){
    string input;
    cin>>input;
    int count=0;
    for(int i = 0;i<input.size();++i){
        if(input[i]=='c'&&(input[i+1]=='='||input[i+1]=='-')) {
            ++i;
        }
        else if(input[i]=='l'&&input[i+1]=='j') {
            ++i;
        }
        else if(input[i]=='n'&&input[i+1]=='j') {
            ++i;
        }
        else if(input[i]=='s'&&input[i+1]=='=') {
            ++i;
        }
        else if(input[i]=='z'&&input[i+1]=='=') {
            ++i;
        }
        else if(input[i]=='d') {    // 같은 조건을 따로 나눠놓으면, 먼저 충족하는 조건만 체크후 검사하지 않으므로 주의
            if(input[i+1]=='z'&&input[i+2]=='=') i+=2;
            else if(input[i+1]=='-') ++i;
        }
        ++count;
    }
    cout<<count;
    return 0;
}