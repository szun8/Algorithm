#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int board[3];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    
    vector<pair<int, int>> cur(3), next(3);
    for (int i = 0; i < n; i++) {
        cin >> board[0] >> board[1] >> board[2];
        if (i == 0) {
            for (int j = 0; j < 3; j++) {
                cur[j].first = cur[j].second = board[j];
                next[j].first = next[j].second = board[j];  // 사이즈가 1인 경우, 바로 반복문 탈출하고 next를 출력하기 때문에 여기에 초기화 필요
            } continue;
        }

        // 1
        next[0].first = board[0] + min(cur[0].first, cur[1].first);
        next[0].second = board[0] + max(cur[0].second, cur[1].second);
        //2
        next[1].first = board[1] + min({ cur[0].first, cur[1].first, cur[2].first });
        next[1].second = board[1] + max({ cur[0].second, cur[1].second, cur[2].second });
        //3
        next[2].first = board[2] + min(cur[1].first, cur[2].first);
        next[2].second = board[2] + max(cur[1].second, cur[2].second);

        cur = next;
    }
    int resultMin = min({ next[0].first, next[1].first, next[2].first });
    int resultMax = max({ next[0].second, next[1].second, next[2].second });
    printf("%d %d", resultMax, resultMin);
    return 0;
}