#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n,m,ix,iy,friends=0;    // 세로, 가로, 도연이의 좌표변수,친구를 만난 수
char map[601][601];
bool visited[601][601];

// 이동 좌표
int moveX[4]={1,0,-1,0};
int moveY[4]={0,1,0,-1};

void DFS(int y, int x){
    if(map[y][x]=='P') ++friends;   // 도연이가 이동한 곳이 친구가 있는 곳이라면 카운팅
    visited[y][x]=true;             // 방문처리

    for (int i = 0; i < 4; i++) {
        int ny = y+moveY[i];
        int nx = x+moveX[i];
        if(ny>=0 && nx>=0 && ny<n && nx<m && visited[ny][nx]==false && map[ny][nx]!='X') DFS(ny,nx);
    }
    
}

int main(){
    memset(visited,false,sizeof(visited));
    cin>>n>>m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin>>map[i][j];
            if(map[i][j]=='I'){
                iy=i; ix=j;     //  도연이의 위치 저장
            }
        }
    }
    DFS(iy, ix);
    if(friends==0) cout<<"TT";
    else cout<<friends;

    return 0;
}
