#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    vector<int> potion(n);
    for (int i = 0; i < n; i++) {
        cin >> potion[i];
    } sort(potion.begin(), potion.end());

    int tmp, left = 0, right = n - 1;
    int result = 1e9*2+1; // 두 용액을 더한 비굣값으로 1억 + 1억보다 큰 값으로 초기화 되어야함
    int leftIdx = 0, rightIdx = n-1;
    while (left < right) {
        tmp = potion[left] + potion[right];

        if (abs(tmp) < abs(result)) {   // 절댓값 비교해서 더 작은 쪽으로 갱신
            result = tmp;
            leftIdx = left, rightIdx = right;
        }
        if (tmp < 0) { // left+1
            left += 1;
        }else if (tmp > 0) { // right-1
            right -= 1;
        }else {
            break;
        }
    }

    printf("%d %d", potion[leftIdx], potion[rightIdx]);
    return 0;
}