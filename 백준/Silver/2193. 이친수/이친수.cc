#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n; cin >> n;
	vector < vector<long long>> dp(n + 1, vector<long long>(2, 0));
	dp[1][1] = 1;

	for (int i = 2; i <= n; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
	}

	printf("%lld", dp[n][0] + dp[n][1]);
	return 0;
}