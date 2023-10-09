#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct MapCoor
{
    int x, y;
} point;

// 우 하 좌 상
int moveX[4] = {1, 0, -1, 0};
int moveY[4] = {0, 1, 0, -1};

vector<vector<int> > input, output;
vector<vector<bool> > visited;

int twoX, twoY;
int n, m;

// 확인 범위 : 0 ~ n-1 && 0 ~ m-1
// 0이면 갈 수 없다
// 1이면 갈 수 있다
// 2면 목표지점이다 -> output is 0
void BFS(int x, int y){
    queue<MapCoor> ingPoints;
    point.x = x, point.y = y;
    ingPoints.push(point);

    while(!ingPoints.empty()){
        point.x = ingPoints.front().x;
        point.y = ingPoints.front().y;

        ingPoints.pop();

        for(int i=0; i<4; i++){
            int nextPointX = point.x+moveX[i];
            int nextPointY = point.y+moveY[i];

            if( nextPointX < m && nextPointX>= 0 && nextPointY < n && nextPointY>= 0 && !visited[nextPointY][nextPointX]){
                if(input[nextPointY][nextPointX]==1){
                    output[nextPointY][nextPointX]=output[point.y][point.x]+1;

                    MapCoor newPoint = {nextPointX, nextPointY};
                    ingPoints.push(newPoint);
                }
                else {   // input is 0
                    output[nextPointY][nextPointX]=0;
                }
                visited[nextPointY][nextPointX] = true;
            }
        }
    }
}

int main(){
    cin>>n>>m;
    input.resize(n, vector<int>(m));
    output.resize(n, vector<int>(m, -1));

    visited.resize(n, vector<bool>(m, false));

    // 갈 수 있는 영역 입력---------------
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>input[i][j];
            if(input[i][j]==2){
                twoX = j, twoY = i;
                output[i][j] = 0;
            }
            else if(input[i][j] == 0) output[i][j] = 0;
            // 0인 구간 전체가 0으로 출력되게 코드를 짰어야함
            // 그렇지 않으면 아예 방문되지 못한 점이 0일수 있는데 초기화 값 -1로 출력돼서 틀리게 됐었음
        }
    }

    BFS(twoX, twoY);

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            printf("%d ", output[i][j]);
        }
        printf("\n");
    }
    return 0;
}