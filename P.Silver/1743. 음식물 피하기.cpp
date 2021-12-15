#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,m,k,area;
int map[101][101];

// 이동 : 우 상 좌 하
int moveX[4]={1,0,-1,0};
int moveY[4]={0,1,0,-1};

void dfs(int y, int x){
    map[y][x]=-1;
    ++area;
    for (int i = 0; i < 4; i++){
        int ny = y + moveY[i];
        int nx = x + moveX[i];
        if(ny>=0 && nx>=0 && ny<=n && nx<=m && map[ny][nx]==1) dfs(ny,nx);
    }
}
int main(){
    cin>>n>>m>>k;
    vector<int> trash;

    for (int i = 0; i < k; i++) {
        int x,y;
        cin>>y>>x;
        map[y-1][x-1] = 1;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(map[i][j]==1){
                area=0;
                dfs(i,j);
                trash.push_back(area);
            }
        }
    }
    trash.size()==0 ? cout<< 0 : cout<< *max_element(trash.begin(),trash.end());
    return 0;
}