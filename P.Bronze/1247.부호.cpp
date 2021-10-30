#include <iostream>
using namespace std;

int main(){
    for(int i =0;i<3;i++){
        int num;
        cin >> num;
        __int128_t sum = 0;
        // num을 허용하는 수는 long long => 즉, 최대가능 수를 2번 이상 더하면 오버플로우가 발생할 수 있음
        // 더 큰 범위의 자료형을 사용해줘야 맞을수있다
        for(int j=0;j<num;++j){
            long long n;
            cin >> n;
            sum += n;
        }
        if(sum < 0) cout<<"-"<<endl;
        else if(sum > 0) cout<<"+"<<endl;
        else cout<<0<<endl;
    }
    return 0;
}