#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int map[501][501];
int n,m,area;

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
        // 벽의 범위 조건 조심!
    }
}

int main(){
    cin>>n>>m;
    vector<int> drawing;
    // input
    for (int i = 0; i < n; i++) {   //세로
        for (int j = 0; j < m; j++) {   //가로
            cin>>map[i][j];
        }
    }
    // search
    for (int i = 0; i < n; i++) {   //세로
        for (int j = 0; j < m; j++) {   //가로
            if(map[i][j]==1){
                area=0;
                dfs(i,j);
                drawing.push_back(area);
            }
        }
    }
    // output
    cout<< drawing.size()<<"\n";
    drawing.size()==0 ? cout<< 0 : cout<< *max_element(drawing.begin(),drawing.end());
    return 0;
}