#include <iostream>
using namespace std;

int main(){
    // 첫째 줄에는 상덕버거, 둘째 줄에는 중덕버거, 셋째 줄에는 하덕버거의 가격
    // 넷째 줄에는 콜라의 가격, 다섯째 줄에는 사이다의 가격
    int sum=0;
    for(int i =0;i<5;i++){
        int num;
        cin>>num;
        if(num<40) num=40;
        sum+=num;
    }
    cout<<sum/5;
    return 0;
}