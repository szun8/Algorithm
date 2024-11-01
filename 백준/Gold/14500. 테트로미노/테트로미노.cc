#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
	int x, y;
	int weight;
};

int n, m;
int maxWeight = -1;
int moveX[4] = {-1, 0, 1, 0};
int moveY[4] = {0, 1, 0, -1};
vector<vector<int>> graph;
vector<vector<bool>> visited;

bool CheckArea(Point point) { // [x, y]
	if (point.x >= 0 && point.x < n && point.y >= 0 && point.y < m) return true;
	else return false;
}

void DFS(Point start, int cnt) {
	if (visited[start.x][start.y]) return;
	visited[start.x][start.y] = true;

	if (cnt == 4) {
		if (maxWeight < start.weight) {
			maxWeight = start.weight;
		}
		visited[start.x][start.y] = false;
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (CheckArea({ start.x + moveX[i], start.y + moveY[i] })) {
			Point nextPoint = { start.x + moveX[i], start.y + moveY[i], start.weight + graph[nextPoint.x][nextPoint.y] };
			if (!visited[nextPoint.x][nextPoint.y]) {
				DFS(nextPoint, cnt + 1);
			}
		}
	}
	visited[start.x][start.y] = false;
}

int maxT;
void T(Point start) {
	for (int i = 0; i < 4; i++) {	// 4방향 회전에 대한 ㅗ모양 최댓값 확인
		maxT = graph[start.x][start.y];
		for (int j = 0; j < 4; j++) {
			if (i == j) continue;
			if (CheckArea({ start.x + moveX[j], start.y + moveY[j] })) {
				maxT += graph[start.x + moveX[j]][start.y + moveY[j]];
			}
		}
		if (maxWeight < maxT) maxWeight = maxT;
	}
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	graph.resize(n, vector<int>(m));
	visited.resize(n, vector<bool>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			DFS({ i, j, graph[i][j] }, 1);
			T({ i, j, graph[i][j] });
		}
	}

	printf("%d", maxWeight);
	return 0;
}