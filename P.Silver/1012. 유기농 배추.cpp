#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int m, n, k; // 가로, 세로, 배추
int map[51][51];

// 1) 우, 상, 좌, 하 순으로 좌표검색 (y가 위로, x가 오른쪽 기준)
// 2) 우, 하, 좌, 상 순으로 좌표검색 (y가 아래로, x가 오른쪽 기준)
int moveY[4] = { 0, 1, 0, -1 };
int moveX[4] = { 1, 0, -1, 0 };

void DFS(int a, int b) {
	//[y][x]
    map[a][b] = 0; // visited
    for (int l = 0; l < 4; ++l) {
        int y = moveY[l] + a;
        int x = moveX[l] + b;
        if (x >= 0 && y >= 0 && x < m && y < n && map[y][x] == 1) DFS(y, x);
    }
}
 
int main() {
    int t;  cin>>t;
    while (t--) {
        int cnt = 0;
        // 지렁이 카운팅
        // 매 케이스마다 초기화해주는 것을 잊지말긔,,,ㅜㅜ~
        // 초기 시도에 전역으로 초기화 한번만 해줘서
        // 여러 케이스일 경우, 정답이 합쳐서 나오는 경우로 1번 틀림
        memset(map, 0, sizeof(map));
        cin >> m >> n >> k;

        for (int i = 0; i < k; i++) {   // input
            int x,y;
            cin>>x>>y;
            map[y][x] = 1;
        }

        if(k==1) {
            cout<<"1\n";
            continue;
        }

        for (int i = 0; i < n; ++i) {   // y
            for (int j = 0; j < m; ++j) {   // x
                if (map[i][j] == 1) {
                    DFS(i, j);      // (y, x) = [y][x]
                    ++cnt;
                }
		    }   
	    }
        cout<<cnt<<"\n";
    }
	return 0;
}