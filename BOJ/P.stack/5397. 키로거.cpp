#include <iostream>
#include <stack>
using namespace std;
int main(){
    int t; cin>>t;
    while (t--) {
        stack<char> password;   
        stack<char> tmp;        // 커서 이동 및 출력을 위한 임시저장 스택
        string what; cin>>what;
        for (int i = 0; i < what.size(); i++) {
            if(what[i]=='-') {  // 백스페이스
                if(!password.empty()){
                    password.pop();
                }
            }
            else if(what[i]=='<'){  // 커서 왼쪽 이동
                if(!password.empty()) {
                    tmp.push(password.top());
                    password.pop();
                }
            }
            else if(what[i]=='>'){  // 커서 오른쪽 이동
                if(!tmp.empty()){
                    password.push(tmp.top());
                    tmp.pop();
                }
            }
            else{   // 이외의 문자 입력시,
                password.push(what[i]);
            }
        }
        while (!tmp.empty()) {
            password.push(tmp.top());
            tmp.pop();
        }
        while(!password.empty()) {  // 문자열 reverse
            tmp.push(password.top());
            password.pop();
        }
        while(!tmp.empty()) {   // 출력
            cout<<tmp.top();
            tmp.pop();
        }
        cout<<endl;
    }
    return 0;
}