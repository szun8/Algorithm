#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <utility>
using namespace std;

int map[101][101];  // 1 = 길, 0 = 벽
int path[101][101]; // 해당칸까지의 최소이동횟수 저장
bool visited[101][101];
int n,m;

// 우, 하, 좌, 상 순으로 좌표검색 (y가 아래로, x가 오른쪽 기준)
int moveY[4] = { 0, 1, 0, -1 };
int moveX[4] = { 1, 0, -1, 0 };

void bfs(int y, int x){ // 0, 0 start
    queue<pair<int,int> > spot; //y,x
    path[y][x] = 1;
    visited[y][x] = true;
    spot.push(make_pair(y, x));
    while (!spot.empty()) {
        y = spot.front().first;
        x = spot.front().second;
        spot.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + moveY[i];
            int nx = x + moveX[i];
            if(nx >= 0 && ny >= 0 && nx < m && ny < n && visited[ny][nx]==false && map[ny][nx]==1){
                visited[ny][nx]=true;
                spot.push(make_pair(ny,nx));
                path[ny][nx] = path[y][x] + 1;
                // 자식칸(자식의 이동횟수) = 부모칸(부모의 이동횟수) + 1

                // Q) 그냥 칸을 방문할 때마다 경로 카운트를 하면 안되는 이유?
                // A) 상하좌우의 탐색순서가 항상 모든 케이스에 있어서 올바르다고 할수없고, 탐색순서가 상하좌우 혹 우좌상하 등의 방향제시는 다양함
                // 정답 방향을 한 칸 남겨두었지만 항상 그 정답칸으로 가는게 아니라 다른 방향으로 갔다가 갈수있는 경우의 수가 있음
                // 그래서 부모칸의 이동횟수에서 이동가능한 자식 칸들은 부모칸을 기준으로 +1 해주는 것
                // 최종적으로 그 칸이 최소 이동수일수있다.
            }
        }
    }
}

int main(){
    cin>>n>>m;  // y, x
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < n; i++) {
        string way;
        cin>>way;
        for (int j = 0; j < way.size(); j++) {
            map[i][j] = way[j]-'0';
        }
    }

    bfs(0,0);
    cout<<path[n-1][m-1];
    return 0;
}