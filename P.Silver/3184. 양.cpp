#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int r,c,sheep,wolf;
char map[251][251];

// 이동 : 우 상 좌 하
int moveX[4]={1,0,-1,0};
int moveY[4]={0,1,0,-1};

void dfs(int y,int x){
    if(map[y][x]=='o') ++sheep;
    else if(map[y][x]=='v') ++wolf;
    map[y][x]='x';  //방문표시

    for (int i = 0; i < 4; i++) {
        int ny = y + moveY[i];
        int nx = x + moveX[i];
        if(ny>=0 && nx>=0 && ny<=r && nx<=c && map[ny][nx]!='#' && map[ny][nx]!='x') dfs(ny,nx);
        // 범위 안이고 울타리가 아니고 방문하지 않았던 곳이라면 == 갈수있는 길!
    }
}

int main(){
    cin>>r>>c;
    int totalSheep = 0, totalWolf = 0;
    for (int i = 0; i < r; i++) {
        string madang;
        cin>>madang;
        for (int j = 0; j < madang.size(); j++) {
            map[i][j] = madang[j];
        }
    }
    
    for (int i = 0; i < r; i++) {   //세로
        for (int j = 0; j < c; j++) {   //가로
            if(map[i][j]!='#' && map[i][j]!='x'){
                sheep=0; wolf=0;
                dfs(i,j);
                if(sheep>wolf) totalSheep+=sheep;
                else totalWolf+=wolf;
            }
        }
    }
    cout<<totalSheep<<" "<<totalWolf;
    return 0;
}