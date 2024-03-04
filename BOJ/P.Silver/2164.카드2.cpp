#include <iostream>
#include <queue>
using namespace std;

int main(){
    int n;
    cin>>n;
    // 100% 됐다가 틀린 이유 : 1을 간과...ㅜㅜ
    if(n==1){
        cout<<"1";
        return 0;
    }
    queue<int> num;
    for(int i=2;i<=n;i++){
        num.push(i);
    }
    while(num.size()>1){
        num.push(num.front());
        num.pop();

        num.pop();  // 걍 삭제
    }
    cout<<num.front();
    return 0;
}