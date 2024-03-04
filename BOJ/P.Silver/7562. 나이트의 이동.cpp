#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

class Knight{
public:
    int x,y;
    Knight(int a,int b){
        x=a; y=b;
    }
};
queue<Knight> spot;
int path[301][301];
bool visited[301][301];
int l,dx,dy,ax,ay;  // 가로세로 크기, 시작점x/y, 도착점x/y

// 나이트의 현좌표에서 이동할 수 있는 범위 좌표
int moveX[8] = {2,1,-1,-2,-2,-1,1,2};
int moveY[8] = {1,2,2,1,-1,-2,-2,-1};

void BFS(){
    while (!spot.empty()) {
        int y = spot.front().y;
        int x = spot.front().x;
        spot.pop();
        for (int i = 0; i < 8; i++) {
            int ny = y + moveY[i];
            int nx = x + moveX[i];
            if(ny==ay && nx==ax) {  // 도착점 좌표
                cout<<path[y][x]<<"\n";
                return ;
            }
            else if(ny>=0 && nx>=0 && ny<l && nx<l && visited[ny][nx]==false){
                path[ny][nx]= path[y][x]+1;
                visited[ny][nx]=true;
                Knight knight(nx, ny);
                spot.push(knight);
            }
        }
    }
}
int main(){
    int t;
    cin>>t;
    while (t--) {
        while(!spot.empty()) spot.pop();
        memset(path,0,sizeof(path));
        memset(visited,false,sizeof(visited));
        cin>>l;
        cin>>dx>>dy;
        path[dy][dx]=1;
        visited[dy][dx]=true;
        Knight knight(dx, dy);
        spot.push(knight);
        cin>>ax>>ay;
        if(ax==dx && ay==dy) cout<<"0\n";
        else BFS();
    }
    return 0;
}