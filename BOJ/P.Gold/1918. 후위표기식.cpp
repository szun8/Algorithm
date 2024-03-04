#include <iostream>
#include <stack>
using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    string s, answer="";
    cin>>s;

    stack<char> oper;

    for(int i=0; i<s.length(); i++){
        if(isalpha(s[i])) answer+=s[i];

        else if(s[i]=='(') oper.push(s[i]);
        else if(s[i]==')'){
            while (oper.top()!='(') {
                answer+=oper.top();
                oper.pop();
            }
            oper.pop(); // '(' 까지 pop
        }
        else if(s[i]=='+' || s[i]=='-'){
            while (!oper.empty() && oper.top()!='(') {
                answer+=oper.top();
                oper.pop();
            }
            oper.push(s[i]);
        }
        else{   // * 이거나 / 인 경우,
            while(!oper.empty() && (oper.top()=='*' || oper.top()=='/')) {
                answer+=oper.top();
                oper.pop();
            }
            oper.push(s[i]);
        }
    }

    while(!oper.empty()){
        answer+=oper.top();
        oper.pop();
    }
    cout<<answer;
    return 0;
}