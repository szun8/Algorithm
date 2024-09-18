#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> RGB;
int main() {
    // 8줄이라면 24번만에 끝남 -> 최종 시간복잡도 O(3N)
    int n; cin >> n;
    RGB.resize(n);

    int r, g, b;
    for (int i = 0; i < n; i++) {
        cin >> r >> g >> b;
        RGB[i] = {r, g, b};
    }

    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j < 3; j++) {
             // 자기 자식중 가장 비용이 작은 친구 선택
            RGB[i][j] += min(RGB[i+1][(j + 1) % 3], RGB[i+1][(j + 2) % 3]);
        }
    }
    printf("%d", *min_element(RGB[0].begin(), RGB[0].end()));
    return 0;
}