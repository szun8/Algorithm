#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<long long> solution(n);
    for (int i = 0; i < n; i++) {
        cin >> solution[i];
    } sort(solution.begin(), solution.end());

    long long result = LLONG_MAX;
    vector<long long> ans(3);

    for (int i = 0; i < n - 2; i++) { // 첫 번째 용액을 고정하고 나머지 두 용액을 투 포인터로 찾습니다
        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            long long sum = solution[i] + solution[left] + solution[right];
            if (abs(sum) < abs(result)) {
                result = sum;
                ans[0] = solution[i];
                ans[1] = solution[left];
                ans[2] = solution[right];
            }

            if (sum < 0) left++;
            else if (sum > 0) right--;
            else {
                cout << ans[0] << " " << ans[1] << " " << ans[2] << "\n";
                return 0;
            }
        }
    }

    cout << ans[0] << " " << ans[1] << " " << ans[2] << "\n";
    return 0;
}