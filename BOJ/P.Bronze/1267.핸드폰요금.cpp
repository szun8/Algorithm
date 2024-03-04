#include <iostream>
using namespace std;

int main(){
    int input;
    cin >> input;
    int Ysum = 0, Msum = 0;

    for(int i=1;i<=input;++i){
        int cost;
        cin >> cost;
        // 영식 요금제
        if(cost/30 == 0) Ysum+=10;
        else Ysum += (((cost/30)+1)*10);
        
        // 민식 요금제
        if(cost/60 == 0) Msum+=15;
        else Msum += (((cost/60)+1)*15);
    }

    if(Ysum == Msum) cout << "Y M "<<Ysum;
    else if(Ysum>Msum) cout << "M "<<Msum;
    else cout << "Y "<< Ysum;
    return 0;
}