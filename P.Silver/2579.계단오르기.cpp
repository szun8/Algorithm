#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
  
int main(){
    int n;
    cin>>n;

    vector<int> cost(n+1,0);    // 각 계단의 점수
    vector<int> stair(n+1,0);   // 각 계단까지 오는데 얻을 수 있는 최대 점수

    for(int i=1;i<=n; i++){
        cin>>cost[i];
    }

    stair[1] = cost[1];
    stair[2] = cost[1]+cost[2];
    stair[3] = cost[1]+cost[3] > cost[1]+cost[2] ? cost[1]+cost[3] : cost[1]+cost[2];

    for(int i=4;i<=n;i++){
        // 현재 계단까지 얻을 수 있는 최대 점수 = 현재 계단 점수 + max(3단계전의 계단까지의 최대 점수 + 1단계전의 계단의 점수, 2단계 계단까지의 최대 점수)
        stair[i] = max(stair[i-3]+cost[i-1]+cost[i], stair[i-2]+cost[i]);
    }

    cout<<stair[n];
    return 0;
}