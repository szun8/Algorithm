#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<vector<int> > rgb(n);    // 각 위치의 비용을 저장하는 벡터
    vector<vector<int> > rgbCost(n, vector <int>(3,0));     // 누적 최소 비용을 저장하는 벡터
    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++){
            int cost;
            cin >> cost;
            rgb[i].push_back(cost);
        }
    }
    // 시작 비용 초기화
    rgbCost[0][0] = rgb[0][0];
    rgbCost[0][1] = rgb[0][1];
    rgbCost[0][2] = rgb[0][2];

    for(int i=1; i<n; i++){
        for(int j=0; j<3; j++){
            if(j==0){
                rgbCost[i][j] = min(rgbCost[i-1][j+1], rgbCost[i-1][j+2])+ rgb[i][j];
            }
            else if(j==1){
                rgbCost[i][j] = min(rgbCost[i-1][j-1], rgbCost[i-1][j+1])+ rgb[i][j];
            }
            else if(j==2){
                rgbCost[i][j] = min(rgbCost[i-1][j-1], rgbCost[i-1][j-2])+ rgb[i][j];
            }
        }
    }

    cout<<*min_element(rgbCost[n-1].begin(), rgbCost[n-1].end());
    return 0;
}