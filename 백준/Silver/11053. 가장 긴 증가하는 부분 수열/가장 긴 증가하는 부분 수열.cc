#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> value(n), dp(n, 1);
    for (int i = 0; i < n; i++) {
        cin >> value[i];
    }

    for (int i = 0; i < n; i++) {
        int length = -1;
        for (int j = 0; j < i; j++) {
            if (value[j] < value[i] && dp[j] >= length) {
                dp[i] = dp[j] + 1;
                length = dp[i];
            }
        }
    }
    printf("%d", *max_element(dp.begin(), dp.end()));
    return 0;
}