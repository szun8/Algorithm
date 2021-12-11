#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n, height=1, h=0;
int map[110][110];
bool visited[110][110];

// 1) 우, 상, 좌, 하 순으로 좌표검색 (y가 위로, x가 오른쪽 기준)
// 2) 우, 하, 좌, 상 순으로 좌표검색 (y가 아래로, x가 오른쪽 기준)
int moveX[4] = { 1, 0, -1, 0 };
int moveY[4] = { 0, 1, 0, -1 };

void notSafe(int a, int b) {
	//[y][x]
    map[a][b] = 0; // 안전하지 못한 곳 처리
    visited[a][b] = true;   // 방문
    for (int l = 0; l < 4; ++l) {
        int y = moveY[l] + a;
        int x = moveX[l] + b;
        if (x >= 0 && y >= 0 && x < n && y < n) {
            if(map[y][x] <= height && visited[y][x] == false)
                notSafe(y, x);
        }
    }
}

void DFS(int a, int b) {
	//[y][x]
    visited[a][b] = true; // visited
    for (int l = 0; l < 4; ++l) {
        int y = moveY[l] + a;
        int x = moveX[l] + b;
        if (x >= 0 && y >= 0 && x < n && y < n) {
            if(map[y][x] > height && visited[y][x] == false)
                DFS(y, x);
        }
    }
}
 
int main() {
    vector<int> safeArea;
    cin>>n;
    // 여러 케이스일 경우, 정답이 합쳐서 나오는 경우로 1번 틀림
    memset(map, 0, sizeof(map));

    // map input
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin>>map[i][j];
            if(h < map[i][j]) h = map[i][j]; // 최대 높이 구하기
        }
    }
    if(h==1){
        cout<<"1";
        return 0;
    }
    
    while(height<h){
        memset(visited, false, sizeof(visited));
        int cnt=0;
        for (int i = 0; i < n; ++i) {   // y
            for (int j = 0; j < n; ++j) {   // x
                if (map[i][j] <= height && visited[i][j] == false) {
                    notSafe(i, j);      // (y, x) = [y][x]
                }
            }   
        }
        memset(visited, false, sizeof(visited));
        for (int i = 0; i < n; ++i) {   // y
            for (int j = 0; j < n; ++j) {   // x
                if (map[i][j] > height && visited[i][j] == false) {
                    DFS(i, j);      // (y, x) = [y][x]
                    ++cnt;
                }
            }   
        }
        safeArea.push_back(cnt);
        ++height;
    }
    cout<<*max_element(safeArea.begin(),safeArea.end());
	return 0;
}