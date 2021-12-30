#include <iostream>
#include <cstring>
using namespace std;

char map[101][101];
bool visited[101][101];
int n,m,area;

int moveX[4]={1,0,-1,0};
int moveY[4]={0,1,0,-1};
void dfs(int y, int x){
    ++area;
    visited[y][x]=true;
    for (int i = 0; i < 4; i++){
        int ny=y+moveY[i];
        int nx=x+moveX[i];
        if(ny>=0 && nx>=0 && ny<m && nx<n && visited[ny][nx]==false && map[y][x]==map[ny][nx]) dfs(ny,nx);
    }
}
int main(){
    int white=0, blue=0;
    cin>>n>>m;
    memset(visited,false,sizeof(visited));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin>>map[i][j];
        } 
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if(visited[i][j]==false){
                area=0;
                dfs(i,j);
                if(map[i][j]=='W') white+=(area*area);
                else blue+=(area*area);
            }
        }
    }
    cout<<white<<" "<<blue;
    return 0;
}