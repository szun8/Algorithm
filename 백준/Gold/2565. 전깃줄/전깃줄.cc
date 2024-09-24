#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n; cin >> n;
    vector<pair<int, int>> value;   // first = from, second = to

    for (int i = 0; i < n; i++) {
        int from, to;
        cin >> from >> to;
        value.push_back({ from, to });
    }
    sort(value.begin(), value.end());

    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++) {
        int length = -1;
        for (int j = 0; j < i; j++) {
            if (value[i].second > value[j].second && dp[j] >= length) {
                dp[i] = dp[j] + 1;
                length = dp[i];
            }
        }
    }

    printf("%d", n - *max_element(dp.begin(), dp.end()));
    return 0;
}