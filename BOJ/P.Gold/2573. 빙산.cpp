#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n,m,cnt=0;
int map[301][301];
int path[301][301];         // 칸 주변에 녹이게하는 0의 갯수를 저장하는 배열
bool visited[301][301];     // 방문여부

int moveX[4]={1,0,-1,0};
int moveY[4]={0,1,0,-1};

void ice(int y, int x){
    int num=0;
    visited[y][x]=true;
    for (int i = 0; i < 4; i++) {
        int ny = y + moveY[i];
        int nx = x + moveX[i];
        if(ny>=0 && nx>=0 && ny<n && nx<m) {
            if(map[ny][nx]==0) ++num;
            else if(visited[ny][nx]==false && map[ny][nx]>0) ice(ny,nx);
        }
    }
    path[y][x]=num;
}

void afterYear(){   // 한번 순회하고 한 칸에 대해 녹는 만큼 빼주는 함수
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(map[i][j]>0) {
                map[i][j]-=path[i][j];
                if(map[i][j]<0) map[i][j]=0;
            }
        }
    }
}

bool isMelted(){    // 빙산이 다 녹았는지 확인하는 함수
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(map[i][j]!=0) return false;
        } 
    }
    return true;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n>>m;  // 세로, 가로
    int year=0;
    for (int i = 0; i < n; i++) {   // 입력
        for (int j = 0; j < m; j++) {
            cin>>map[i][j];
        }
    }
    while (cnt<2) {
        cnt=0;
        memset(visited,false,sizeof(visited));
        memset(path,0,sizeof(path));
        
        if(isMelted()==true) {  // 녹을 빙산이 더이상 없는데 조건불충족이라면!
            cout<<0;
            return 0;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(map[i][j]>0 && visited[i][j]==false){
                    cnt++;
                    if(cnt==2){ // 빙산이 딱 처음으로 두개로 쪼개지는 순간을 출력
                        cout<<year;
                        return 0;
                    }
                    ice(i,j);
                    afterYear();
                }
            }
        }
        ++year;
    }
    return 0;
}