#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n; cin >> n;

	vector<int> dp(n+2, 0);
	vector<int> time(n + 1), price(n + 1);

	for (int i = 1; i<= n; i++) {
		cin >> time[i] >> price[i];
	}

	for (int i = n; i > 0; i--) {
		if (i + time[i] > n + 1) dp[i] = dp[i + 1];
		else dp[i] = max(dp[i + 1], price[i] + dp[i + time[i]]);
					// 오늘 안하고 이전날짜 갱신 or 오늘 수익 벌고 다음 상담 가능일의 최대 수익
	}
	printf("%d", dp[1]);
	return 0;
}