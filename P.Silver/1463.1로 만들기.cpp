#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> dp(n+1, 0);    // 5까지라면 dp[5]까지 존재해야하기 때문에.

    for(int i=2; i<=n ;++i){
        dp[i] = dp[i-1] + 1;    // 이전 수보다 1차이 나니까 -1하는 방법을 한번 한거라고 생각해서 횟수 +1

        if(i%2==0)  // 2로 나눠 떨어지면
            dp[i] = min(dp[i], dp[i/2]+1);

        if(i%3==0)  // 3으로 나눠 떨어지면
            dp[i] = min(dp[i], dp[i/3]+1);
    }

    cout << dp[n];
    return 0;
}