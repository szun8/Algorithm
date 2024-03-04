#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

bool spot[100001];  // 수빈이가 지나친 경로 check
int path[100001];   // 수빈이가 동생에게 가는 길 count
int n,k;            // 수빈이와 동생의 위치

void FindSister(){
    queue<int> subin;   // 수빈이가 이동한 위치 저장
    subin.push(n);
    while (!subin.empty()) {
        int x = subin.front();
        subin.pop();
        for (int i = 0; i < 3; i++) {
            if(i==0 && x-1>=0 && spot[x-1]==false){   // x-1
                if(x-1==k){     // 찾았다 동생!
                    cout<<path[x];
                    return ;
                }
                else {
                    spot[x-1]=true;
                    path[x-1]=path[x]+1;
                    subin.push(x-1);
                }
            }
            else if(i==1 && x+1<100001 && spot[x+1]==false){    // x+1
                if(x+1==k){     // 찾았다 동생!
                    cout<<path[x];
                    return ;
                }
                else {
                    spot[x+1]=true;
                    path[x+1]=path[x]+1;
                    subin.push(x+1);
                }
            }
            else if(i==2 && x*2<100001 && spot[x*2]==false){    // x*2
                if(x*2==k){     // 찾았다 동생!
                    cout<<path[x];
                    return ;
                }
                else {
                    spot[x*2]=true;
                    path[x*2]=path[x]+1;
                    subin.push(x*2);
                }
            }
        }
    }
}

int main(){
    memset(spot,false,sizeof(spot));
    cin>>n>>k;  // 수빈, 동생의 위치
    if(n==k){
        cout<<0; return 0;
    }
    path[n]=1;
    FindSister();
    return 0;
}