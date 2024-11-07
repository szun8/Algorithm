#include <queue>
#include <vector>
#include <iostream>
using namespace std;
int n,m;
vector<vector<int>> graph;
vector<vector<int>> answer;

int moveX[4] = {0, 1,0,-1};
int moveY[4] = {-1,0,1,0};

void BFS(int startX, int startY){
    queue<pair<int, int> > q;
    q.push({startY, startX});

    while(!q.empty()){
        int curX = q.front().second;
        int curY = q.front().first;
        q.pop();

        for(int i=0; i<4; i++){
            int nextX = moveX[i] +curX;
            int nextY = moveY[i] +curY;
            if(nextX >= 0  && nextY >= 0 && nextX < m && nextY < n){    // 영역 유효성 확인
                if(graph[nextY][nextX] == 1 && answer[nextY][nextX] == -1){   // 갈 수 있는 길 && 미방문 노드에 한해서만
                    answer[nextY][nextX] = answer[curY][curX] + 1;
                    q.push({nextY, nextX});
                }
            }
        }
    }
}
 
int main(){
    cin>>n>>m;
    int startX, startY;
    graph.resize(n, vector<int>(m, 0));
    answer.resize(n, vector<int>(m, -1));
    for(int i=0; i<n; i++){
        for(int j=0; j<m;j++){
            cin>>graph[i][j];
            if(graph[i][j] == 0){
                answer[i][j] = 0;
            }
            else if(graph[i][j] == 2){
                answer[i][j] = 0;
                startX = j;
                startY = i;
            }
        }
    }
    BFS(startX,startY);
    for(int i=0; i<n; i++){
        for(int j=0; j<m;j++){
            printf("%d ", answer[i][j]);
        }printf("\n");
    }
}