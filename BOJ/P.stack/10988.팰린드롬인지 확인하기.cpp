#include <iostream>
#include <stack>
using namespace std;
int main(){
    string str;
    cin>>str;
    int size=str.size()/2;
    stack<char> p1;
    for (int i = 0; i < size; i++) {
        p1.push(str[i]);
    }

    if(str.size()%2==1){
        // 홀수
        for (int i = size+1; i < str.size(); i++)
        {
            if(p1.empty() || p1.top() != str[i]){
                cout<<"0";
                return 0;
            }
            p1.pop();
        }
    }
    else{
        // 짝수
        for (int i = size; i < str.size(); i++)
        {
            if(p1.empty() || p1.top() != str[i]){
                cout<<"0";
                return 0;
            }
            p1.pop();
        }
    }

    // all continue
    cout<<"1";
    
    return 0;
}