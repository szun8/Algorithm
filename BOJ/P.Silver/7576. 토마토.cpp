#include <iostream>
#include <queue>
#include <algorithm>    // find
using namespace std;
int m,n,days;
int map[1001][1001];
int path[1001][1001];
int moveX[4] = {1,0,-1,0};
int moveY[4] = {0,1,0,-1};
queue<Tomato> q;
class Tomato{
public:
    int y,x;
    Tomato(int a,int b){
        y=a; x=b;
    }
};

void tomato(){  // BFS
// queue의 성질(선입선출)을 잘이용해서 오버플로우를 조심!
// 굳이 vector로 1의 위치를 안돌려도 들어온 1이 들어온 순서대로 지도를 돌기때문에 하나의 queue로만으로도 문제해결가능
    while(!q.empty()){
        int y = q.front().y;
        int x = q.front().x;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + moveY[i];
            int nx = x + moveX[i];
            if(ny>=0 && nx>=0 && ny<n && nx<m && map[ny][nx]==0 && path[ny][nx]==0){
                path[ny][nx] = path[y][x]+1;
                days = path[ny][nx];
                Tomato where(ny,nx);
                q.push(where);
            }
        }
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>m>>n;  // x,y
    fill(&path[0][0],&path[n][m],-1);
    for (int i = 0; i < n; i++) {
        fill(&path[i][0],&path[i][m],0);
        for (int j = 0; j < m; j++) {
            cin>>map[i][j];
            if(map[i][j]==-1) path[i][j]=-1;
            else if(map[i][j]==1) {
                Tomato where(i,j);
                q.push(where);
                path[i][j] = 1;
            }
        }
    }
    days=0;
    tomato();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(path[i][j]==0){
                cout<<-1;
                return 0;
            }
        }
    }
    if(days==0) cout<<0;
    else cout<<days-1;
    return 0;
}