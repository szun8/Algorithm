#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    while(true){
        vector<int> num(3);
        // 무조건 들어오는 순서가 가로 세로 대각선이 아니기 때문에
        // 직각 삼각형의 조건에서는 대각선이 가장 길기때문에
        cin>>num[0]>>num[1]>>num[2];
        // 오름차순 정렬로 수를 정렬햐주고
        if(num[0]==0&&num[1]==0&&num[2]==0) return 0;
        sort(num.begin(),num.end());
        // 그 차례된 수들의 피타고라스 정리가 성립하는가를 확인
        if(pow(num[0],2)+pow(num[1],2)==pow(num[2],2)) cout<<"right"<<endl;
        else cout<<"wrong"<<endl;
    }
    return 0;
}