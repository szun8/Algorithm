#include <iostream>
#include <deque>
#include <cstring>
using namespace std;

char map[51][51];           // 지도
bool starVisited[51][51];   // 물이 차올라서 지나간 곳 check
bool SVisited[51][51];      // 고슴도치가 지나간 곳 check
int path[101][101];         // 고슴도치가 지나간 곳 count
int r,c;                    // 지도 가로세로
bool isGo = false;          // 도착여부

// 우 하 좌 상
int moveX[4]={1,0,-1,0};
int moveY[4]={0,1,0,-1};

class Spot {
public:
    int y,x;
    Spot(int a, int b){
        y=a, x=b;
    }
};
deque<Spot> forest;

// S -> D
void BFS(){
    // S가 먼저 움직이고 물이 차는 순으로 탐색진행
    while(!forest.empty()){
        int y = forest.front().y;
        int x = forest.front().x;
        forest.pop_front();
        // 1) 고슴도치 이동
        if(map[y][x]=='S' || map[y][x]=='.'){
            for (int i = 0; i < 4; i++) {
                int ny = y + moveY[i];
                int nx = x + moveX[i];
                if(ny>=0 && nx>=0 && ny<r && nx<c && SVisited[ny][nx]==false){
                    if(map[ny][nx]=='.'){           // 물이 차지 않은 이동가능한 곳
                        SVisited[ny][nx]=true;
                        path[ny][nx]=path[y][x]+1;
                        Spot what(ny,nx);
                        forest.push_back(what);
                    }
                    else if(map[ny][nx]=='D'){      // 도착지점
                        isGo=true;
                        cout<<path[y][x];
                        return ;
                    }
                }
            }
        }
        // 2) 물차오르기 => . 을 * 로 만드는!
        else if(map[y][x]=='*'){
            for (int i = 0; i < 4; i++) {
                int ny = y + moveY[i];
                int nx = x + moveX[i];
                if(ny>=0 && nx>=0 && ny<r && nx<c && starVisited[ny][nx]==false && map[ny][nx]=='.'){
                    starVisited[ny][nx]=true;
                    map[ny][nx]='*';
                    Spot what(ny,nx);
                    forest.push_back(what);
                }
            }
        }
    }
}

int main(){
    memset(SVisited,false,sizeof(SVisited));
    memset(starVisited,false,sizeof(starVisited));
    cin>>r>>c;
    // input
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin>>map[i][j];
            if(map[i][j]=='*'){
                Spot what(i,j);
                forest.push_back(what);
                starVisited[i][j]=true;
            }
            else if(map[i][j]=='S') {
                Spot what(i,j);
                forest.push_front(what);
                path[i][j]=1;
                SVisited[i][j]=true;
            }
        }
    }
    BFS();
    if(isGo==false) cout<<"KAKTUS";
    return 0;
}