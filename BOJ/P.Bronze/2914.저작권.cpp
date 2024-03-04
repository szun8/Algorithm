#include <iostream>

using namespace std;
// 무조건 올림해주니까 평균값 -1을 해서 구해주기
int main(){
    int a,i;
    cin >> a>>i;
    int result = a*(i-1)+1;
    cout<<result;
    return 0;
}