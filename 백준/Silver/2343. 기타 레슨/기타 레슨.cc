#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    vector<int> lesson(n);
    int sum = 0, max = -1;
    for (int i = 0; i < n; i++) {
        cin >> lesson[i];
        sum += lesson[i];
        if (max < lesson[i]) max = lesson[i];
    }

    int left = max, right = sum, mid;
    while (left <= right) {
        mid = (left + right) / 2;

        int tmpSum = 0;
        int tmpCnt = 1;
        for (int i = 0; i < n; i++) {
            if (tmpSum + lesson[i] <= mid) {
                tmpSum += lesson[i];
            }
            else {
                tmpSum = lesson[i];
                tmpCnt++;
            }
        }
        if (tmpCnt <= m) { // 원하는 갯수보다 적게 블루레이가 쓰였다면,
            // 기준 크기를 늘리자 -> right 수정
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    printf("%d", left);
    return 0;
}