#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int w, h; // 가로, 세로
int map[51][51];

// 우, 우하, 하, 하좌, 좌, 좌상, 상, 상우 순으로 좌표검색 (y가 아래로, x가 오른쪽 기준)
int moveX[8] = { 1, 1, 0, -1, -1, -1, 0, 1};
int moveY[8] = { 0, 1, 1, 1, 0, -1, -1, -1};

void DFS(int a, int b) {  //[y][x]
    map[a][b] = 0; // 바다처리
    for (int l = 0; l < 8; ++l) {
        int y = moveY[l] + a;
        int x = moveX[l] + b;
        if (x >= 0 && y >= 0 && x < w && y < h && map[y][x] == 1) DFS(y, x);    // 섬이면 탐색 진행
    }
}
 
int main() {
    while(true){
        cin>>w>>h;
        if(w==0 && h==0) return 0;
        memset(map, 0, sizeof(map));

        // input
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin>>map[i][j];
            }
        }
        int island = 0;
        // dfs
        for (int i = 0; i < h; ++i) {   // y
            for (int j = 0; j < w; ++j) {   // x
                if (map[i][j] == 1) {
                    DFS(i, j);      // (y, x) = [y][x]
                    ++island;
                }
            }
        }
        cout<<island<<"\n";
    }
	
	return 0;
}