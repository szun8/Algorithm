#include<iostream>
using namespace std;

int main(){
    int input1, input2;
    cin >> input1 >> input2;

    string num1 = to_string(input1);
    string Rnum1;
    for(int i = num1.size()-1;i>=0;--i){
        Rnum1.append(1, num1[i]);
    }
    input1 = stoi(Rnum1);
    string num2 = to_string(input2);
    string Rnum2;
    for(int i = num2.size()-1;i>=0;--i){
        Rnum2.append(1, num2[i]);
    }
    input2 = stoi(Rnum2);
    
    if(input1>input2) cout<<input1;
    else cout<<input2;
    return 0;
}