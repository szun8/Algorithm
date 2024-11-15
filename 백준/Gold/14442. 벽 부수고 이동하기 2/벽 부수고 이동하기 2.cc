#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n,m,k;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
struct Point {
    int y, x;
    int brokenCnt;  // 현재까지 부순 갯수
    Point(int _y, int _x, int _b) : y(_y), x(_x), brokenCnt(_b){}
};
vector<string> board;
vector<vector<vector<int>>> dp;

void BFS(){
    queue<Point> q;
    q.push({0,0,0});
    dp[0][0][0] = 1;

    while(!q.empty()){
        Point cur = q.front(); q.pop();
        if(cur.x == m-1 && cur.y == n-1) { // end Point
            printf("%d", dp[cur.y][cur.x][cur.brokenCnt]);
            return;
        }

        for(int i=0; i<4; i++){
            int nx = cur.x +dx[i];
            int ny = cur.y +dy[i];

            if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue; // 범위 휴효성 체크
            else if(board[ny][nx]-'0' == 1){ // 벽인데
                if(cur.brokenCnt < k && dp[ny][nx][cur.brokenCnt+1] == -1){ // 부술수 있고 아직 미방문이라면
                    dp[ny][nx][cur.brokenCnt+1] = dp[cur.y][cur.x][cur.brokenCnt] +1;
                    q.push({ny, nx, cur.brokenCnt+1});
                }
            }else{  // 벽이 아닌 경우
                if(dp[ny][nx][cur.brokenCnt] == -1){ // 미방문이라면
                    dp[ny][nx][cur.brokenCnt] = dp[cur.y][cur.x][cur.brokenCnt] +1;
                    q.push({ny, nx, cur.brokenCnt});
                }
            }
        }
    }   printf("-1");
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n>>m>>k;
    dp.assign(n, vector<vector<int>>(m, vector<int>(k+1, -1)));
    board.resize(n);

    for(int i=0; i<n;i++)
        cin>>board[i];

    BFS();
    return 0;
}