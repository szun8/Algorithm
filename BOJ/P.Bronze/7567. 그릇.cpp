#include <iostream>
using namespace std;
int main(){
    string bowl;
    cin>>bowl;
    int height=10;
    for (int i = 1; i < bowl.size(); i++)
    {
        if((bowl[i]=='(' && bowl[i-1]=='(') || (bowl[i]==')' && bowl[i-1]==')')){   // (( or ))
            height+=5;
        }
        else if((bowl[i]=='(' && bowl[i-1]==')') || (bowl[i]==')' && bowl[i-1]=='(')){ // )( or ()
            height+=10;
        }
    }
    cout<<height;
    return 0;
}