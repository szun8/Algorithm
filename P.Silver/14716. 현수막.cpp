#include <iostream>
#include <cstring>
using namespace std;
int map[251][251];
bool visited[251][251];
int m,n,cnt=0;
int moveX[8] = {1,1,0,-1,-1,-1,0,1,};
int moveY[8] = {0,1,1,1,0,-1,-1,-1};

void dfs(int y, int x){
    visited[y][x]=true;
    for (int i = 0; i < 8; i++) {
        int ny = moveY[i] + y;
        int nx = moveX[i] + x;
        if(ny>=0 && nx>=0 && ny<m && nx<n && visited[ny][nx]==false && map[ny][nx]==1) dfs(ny,nx);
    }
}

int main(){
    cin>>m>>n;
    memset(visited,false,sizeof(visited));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin>>map[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if(visited[i][j]==false && map[i][j]==1) {
                dfs(i,j);
                ++cnt;
            }
        }
    }
    cout<<cnt;
    return 0;
}