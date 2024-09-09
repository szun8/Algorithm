#include <vector>
#include <iostream>
using namespace std;
int main() {
    int n, h; cin >> n >> h;
    vector<int> bottom(h + 1, 0);
    vector<int> up(h + 1, 0);
    vector<int> answer(h + 1, 0);

    for (int i = 0; i < n; i++) {
        int obstacle; cin >> obstacle;
        if (i % 2 == 0) {   // 석순 -> bottom
            bottom[obstacle]++;
        }
        else {  // 종유석 -> up
            up[obstacle]++;
        }
    }

    for (int i = h; i > 0; i--) {
        if (i == h) continue;
        up[i] += up[i + 1];
        bottom[i] += bottom[i + 1];
    }
    
    int upIdx = 1, bottomIdx = h, min = -1;
    while (bottomIdx > 0){
        answer[upIdx] = up[upIdx] + bottom[bottomIdx];
        if (min == -1 || min > answer[upIdx]) min = answer[upIdx];

        bottomIdx--;
        upIdx++;
    }

    int cnt = 0;
    for (int i = 1; i < answer.size(); i++) {
        if (min == answer[i]) cnt++;
    }
    printf("%d %d", min, cnt);
    return 0;
}