#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);

    int n;
    scanf("%d",&n);
    stack<int> s;
    stack<int> o;
    for(int i =0;i<n;++i){
        int num;
        scanf("%d",&num);
        s.push(num);
    }
    // 1st는 무조건 오른쪽이 없으니 (-1) 출력
    o.push(-1);
    stack<int> nums;
    nums.push(s.top());
    s.pop();

    while(!s.empty()){
         if(!nums.empty() && nums.top()>s.top()){
             o.push(nums.top());
             nums.push(s.top());
             s.pop();
         }
         else if(!nums.empty() && nums.top()<=s.top()){
             nums.pop();
         }
         else{
             o.push(-1);
             nums.push(s.top());
             s.pop();
         }
    }

    while(!o.empty()){
        cout<<o.top()<<" ";
        o.pop();
    }
    return 0;
}