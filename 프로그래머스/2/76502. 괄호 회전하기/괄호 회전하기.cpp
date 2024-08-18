#include <string>
#include <unordered_map>
#include <stack>
using namespace std;

int solution(string s) {
    int answer = 0;
    unordered_map<char, int> brackets;
    for(int i=0; i<s.size();i++){
        brackets[s[i]]++;
    }
    
    if(brackets['('] != brackets[')'] ||
       brackets['{'] != brackets['}'] ||
       brackets['['] != brackets[']']) return 0;
    
    int cnt = 0;
    while(cnt < s.size()){
        stack<char> bracketOrder;
        bool isRight = true;
        int totalCnt = 0;
        for(int i=cnt; i<s.size();++i%=s.size()){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') bracketOrder.push(s[i]);
            else if(!bracketOrder.empty() && ((s[i] == ')' && bracketOrder.top() == '(') ||
                    (s[i] == ']' && bracketOrder.top() == '[') ||
                    (s[i] == '}' && bracketOrder.top() == '{')))
                    {  bracketOrder.pop(); }
            else {
                isRight = false;
                break;
            }
            ++totalCnt;
            if(totalCnt == s.size()) break;
        }
        if(isRight) answer++;
        ++cnt;
    }
    
    return answer;
}