#include <iostream>
#include <stack>
using namespace std;
stack<int> origin, comp, result;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin>>n;
    int input;
    for(int i=0; i<n; i++){
        cin>>input;
        origin.push(input);
    }

    while(!origin.empty()){ // 이제 아예 자기보다 큰 값이 없는 경우 -1를 저장해주는 코드가 필요하다
        if(comp.empty()){
            result.push(-1);
            comp.push(origin.top()); origin.pop();
        }
        else if(origin.top() < comp.top()){
            result.push(comp.top());
            comp.push(origin.top()); origin.pop();
        }
        else if(origin.top() >= comp.top()){
            comp.pop();
        }
    }
    while(!result.empty()){
        cout<<result.top()<<" ";
        result.pop();
    }
    return 0;
}