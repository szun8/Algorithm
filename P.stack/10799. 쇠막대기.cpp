#include <iostream>
#include <stack>
using namespace std;
int main(){
    string str;
    cin>>str;

    stack<char> iron;
    int count=0;
    for (int i = 0; i < str.size(); i++) {
        if(str[i]=='('){
            if(str[i+1]==')'){  // 레이저일때,
                count+=iron.size();
                ++i;
            }
            else if(str[i+1]=='(') iron.push('(');
        }
        else {  // 쇠막대기의 끝을 알리는 닫는 괄호일때,
            iron.pop();
            ++count;    // 해당막대기의 끝자락하나 더해주기
        }
    }
    cout<<count;
    return 0;
}