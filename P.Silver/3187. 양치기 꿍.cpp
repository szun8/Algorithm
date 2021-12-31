#include <iostream>
#include <cstring>
using namespace std;
char map[251][251];
bool visited[251][251];
int r,c,sheep,wolf;

int moveX[4]={1,0,-1,0};
int moveY[4]={0,1,0,-1};

void dfs(int y, int x){
    visited[y][x]=true;
    if(map[y][x]=='v') ++wolf;
    else if(map[y][x]=='k') ++sheep;
    for (int i = 0; i < 4; i++) {
        int ny = y + moveY[i];
        int nx = x + moveX[i];
        if(ny>=0 && nx>=0 && ny<r && nx<c && visited[ny][nx]==false && map[ny][nx]!='#') dfs(ny,nx);
    }
}
int main(){
    int sheepCnt=0, wolfCnt=0;
    memset(visited,false,sizeof(visited));
    cin>>r>>c;
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cin>>map[i][j];
        }   
    }

    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            if(map[i][j]!='#' && visited[i][j]==false){
                wolf=0; sheep=0;
                dfs(i,j);
                if(wolf>=sheep) wolfCnt+=wolf;
                else sheepCnt+=sheep;
            }
        }   
    }
    cout<<sheepCnt<<" "<<wolfCnt;
    return 0;
}