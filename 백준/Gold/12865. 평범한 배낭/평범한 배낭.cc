#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n; cin >> n;
    int k; cin >> k;

    vector<vector<int>> dp(n+1, vector<int>(k+1, 0));   // 0번 인덱스는 미활용
    vector<int> w(n + 1), v(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }

    for (int curThing = 1; curThing <= n; curThing++) {
        for (int curLimitWeight = 1; curLimitWeight <= k; curLimitWeight++) {
            if (curLimitWeight < w[curThing])   // 현재 i번째 물건을 넣을 수 없는 limit weight인 경우
                dp[curThing][curLimitWeight] = dp[curThing - 1][curLimitWeight];
            else  // 0-1 knapsack problem...
                dp[curThing][curLimitWeight]    // 현재 물건까지 산정될 수 있는 가치는
                    = max(dp[curThing - 1][curLimitWeight], v[curThing] + dp[curThing - 1][curLimitWeight - w[curThing]]);
                        // 현재 물건을 안담거나              // 현재 물건을 담고 + 나머지 무게로 얻을 수 있는 최대 가치
        }
    }
    printf("%d", dp[n][k]); // 모든 물건을 고려했을 때 -> 최대의 가치 창출
    return 0;
}