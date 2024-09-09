#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    unsigned int n, s;
    int answer = 0;
    cin >> n >> s;
    vector<unsigned int> nums(n, 0);
    vector<unsigned int> sums(n, 0);
    unsigned int start = 0;
    unsigned int end = 1;

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        if (nums[i] == s) {
            printf("1");
            return 0;
        }

        if (i == 0)  sums[i] = nums[i];
        else sums[i] = sums[i-1] + nums[i];

        if (sums[i] == s) { // 0부터 i까지의 누적합이 s인 경우
            answer = i + 1;
        }
    }
    // 이 수열에서 연속된 수들의 부분합 중에 그 합이 S 이상이 되는 것 중, 가장 짧은 것의 길이
    while (start <= end && end < n) {
        if (sums[end] - sums[start] >= s) {
            if (answer == 0 || answer > end - start) {
                answer = end - start;
                if (answer == 2) break;
            }
            start++;
        }
        else if (sums[end] - sums[start] < s) end++;
    }
    printf("%d", answer);
    return 0;
}
