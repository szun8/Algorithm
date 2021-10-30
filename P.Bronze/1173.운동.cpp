#include <iostream>
using namespace std;

int main(){
    int N,m,M,T,R;
    cin >> N>>m>>M>>T>>R;
    // N = 운동시간, m = 최소 맥박, M = 최대 맥박, T = 증가맥박, R = 감소맥박
    int now = m;
    int time = 0;
    if(M-m < T) {
        cout << -1;
        return 0;
    }
    while(N>0){
        if(now+T<=M){
            N--; time++;
            now+=T;
            // 운동선택
        }
        else {
            // 휴식 선택
            time++;
            now-=R;
            if(now<m) now = m;
        }
    }
    cout << time;
    return 0;
}