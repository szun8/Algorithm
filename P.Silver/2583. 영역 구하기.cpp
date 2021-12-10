#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int m, n, k; // 세로(y), 가로(x), 사각형 갯수
int area;
int map[101][101];

// 1) 우, 상, 좌, 하 순으로 좌표검색 (y가 위로, x가 오른쪽 기준)
// 2) 우, 하, 좌, 상 순으로 좌표검색 (y가 아래로, x가 오른쪽 기준)
int moveY[4] = { 0, 1, 0, -1 };
int moveX[4] = { 1, 0, -1, 0 };

void DFS(int a, int b) {
	//[y][x]
    map[a][b] = 1;
    ++area;
    for (int l = 0; l < 4; ++l) {
        int y = moveY[l] + a;
        int x = moveX[l] + b;
        if (x >= 0 && y >= 0 && x < n && y < m && map[y][x] == 0) DFS(y, x);
    }
}
 
int main() {
    vector<int> answer;
    memset(map, 0, sizeof(map));
	int x1, y1, x2, y2;
 
	cin >> m >> n >> k;
 
	while (k--) {
		cin >> x1 >> y1;
		cin >> x2 >> y2;
 
		for (int i = y1; i < y2; ++i) {
			for (int j = x1; j < x2; ++j) map[i][j] = 1;  //[y][x]
		}
	}

	for (int i = 0; i < m; ++i) {   // y
		for (int j = 0; j < n; ++j) {   // x
			if (map[i][j] == 0) {
				area = 0;
				DFS(i, j);      // (y, x) = [y][x]
				answer.push_back(area);
			}
		}
	}
	sort(answer.begin(),answer.end());  // 오름차순
	cout << answer.size() << endl;
 
	for (int i = 0; i < answer.size(); ++i) cout << answer[i] << " ";
 
	return 0;
}