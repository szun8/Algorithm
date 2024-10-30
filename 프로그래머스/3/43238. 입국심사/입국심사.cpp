#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {
    //sort(times.begin(), times.end());

    long long mid, left = times[0], right = (long long)times.back() * n;

    while (left <= right) {
        mid = left + (right - left) / 2;

        long long possibleClientCnt = 0;
        for (int i = 0; i < times.size(); i++) {
            possibleClientCnt += (mid / times[i]);
            if (possibleClientCnt >= n) break;
        }
        if (possibleClientCnt < n) {  // 현재 기준 시간으로는 모든 고객을 받지 못하므로 기준 시간을 높여야함
            left = mid + 1; // left 갱신
        }
        else {
            right = mid - 1;
        }
    }
    return left;
}