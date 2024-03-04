#include <iostream>
#include <queue>
#include <cstring>
#define INF 1e9
using namespace std;
int path[126][126];
int coin[126][126];
int N;

class Coin{
public:
    int x,y,cost;
    Coin(int a,int b, int val){
        x=a;    y=b;    cost=val;
    }
};

int moveX[4]={1,0,-1,0};
int moveY[4]={0,1,0,-1};

void solution(){
    queue<Coin> ing;   // 큰애가 가장 위로 옴
    coin[0][0]=path[0][0];  // 시작점 비용 설정
    Coin info(0,0,path[0][0]);
    ing.push(info);
    while(!ing.empty()){
        int curX = ing.front().x;
        int curY = ing.front().y;
        int curCost = ing.front().cost;
        ing.pop();
        if(curX==N-1 && curY==N-1) continue;    // 도착점이라면 다음으로,
        for (int i = 0; i < 4; i++) {   // 상하좌우 탐색
            int nextX = curX + moveX[i];
            int nextY = curY + moveY[i];
            if(nextX>=0 && nextY>=0 && nextX<N && nextY<N){
                // 올바르지 못한 좌표가 와야만 비용구하기 가능
                int nextCost = path[nextY][nextX];
                if(coin[nextY][nextX] > curCost + nextCost){
                    // 여태입력된 비용누적값보다 적다면, 갱신!
                    coin[nextY][nextX] = curCost + nextCost;
                    Coin info2(nextX,nextY,coin[nextY][nextX]);
                    ing.push(info2);
                }
            }
        }
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int cnt=1;
    while(true){
        cin>>N;
        if(N==0) break;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++){
                cin>>path[i][j];    // 경로별 비용 입력
            }
        }
        fill(&coin[0][0],&coin[N][N],INF);
        solution(); // 탐색
        cout<<"Problem "<<cnt++<<": "<<coin[N-1][N-1]<<"\n";
    }
    return 0;
}