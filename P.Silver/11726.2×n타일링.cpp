#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, result;
    cin >> n;

    if(n==1) result = 1;
    else if(n==2) result = 2;
    else{
        vector<int> dp(n+1, 0);
        dp[1]=1;
        dp[2]=2;
        for(int i=3; i<=n; i++){
            dp[i] = (dp[i-1] + dp[i-2])%10007;  // 숫자가 너무 커져서 항상 
        }
        result = dp[n];
    }
    cout<<result;
    return 0;
}