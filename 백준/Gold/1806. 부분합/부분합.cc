#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    unsigned int n, s;
    cin >> n >> s;
    
    vector<unsigned int> nums(n);
    for (unsigned int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    unsigned int start = 0;
    unsigned int end = 0;
    unsigned int current_sum = 0;
    unsigned int answer = n + 1; // 초기값을 n보다 큰 값으로 설정

    while (end < n) {
        current_sum += nums[end];

        while (current_sum >= s) {
            answer = min(answer, end - start + 1);
            current_sum -= nums[start];
            start++;
        }
        
        end++;
    }

    // 만약 answer가 초기값인 n + 1이라면, 부분합이 s 이상인 연속된 수열이 없다는 의미
    if (answer == n + 1) {
        cout << "0";
    } else {
        cout << answer;
    }

    return 0;
}
