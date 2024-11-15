#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
struct Point {
    int x, y, dir, cost;
    Point(int _x, int _y, int _dir, int _cost) : x(_x), y(_y), dir(_dir), cost(_cost) {}
};

vector<vector<vector<int>>> dp;

int solution(vector<vector<int>> board) {
    int n = board.size();
    dp.assign(n, vector<vector<int>>(n, vector<int>(4, 1e9)));
    
    queue<Point> q;
    q.push({0, 0, -1, 0});
    
    while(!q.empty()) {
        auto [x, y, dir, cost] = q.front(); q.pop();
        
        if(x == n-1 && y == n-1) continue;
        
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n || board[ny][nx]) continue;
            
            int ncost = cost + 100;
            if(dir != -1 && dir != i) ncost += 500;
            
            if(dp[ny][nx][i] >= ncost) {
                dp[ny][nx][i] = ncost;
                q.push({nx, ny, i, ncost});
            }
        }
    }
    
    return min({dp[n-1][n-1][0], dp[n-1][n-1][1], dp[n-1][n-1][2], dp[n-1][n-1][3]});
}
