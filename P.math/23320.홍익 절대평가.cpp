#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> score;
    for(int i =0;i<n;++i){
        int num;
        cin >> num;
        score.push_back(num);
    }
    sort(score.begin(),score.end());
    int ratioR, scoreA;
    cin >> ratioR >> scoreA;

    // 상대평가 시, (비율 적용)
    int r = (n * ratioR)/100; // 총 n명중 A를 받을 수 있는 학생의 수
    int a=0;
    // 절대평가 시, (점수 적용)
    for(int i=0;i<n;++i){
        if(score[i]>=scoreA) {
            a=n-i;  // 총 n명중 A를 받을 수 있는 학생의 수
            break;
        }
    }
    cout<<r<<" "<<a;
    return 0;

}