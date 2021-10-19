#include <vector>
#include <cmath>
#include <iostream>
using namespace std;
// 에라토스테네스의 체

int main() {
    int m,n;    //m~n
    cin >> m >> n;
    vector<int> sosu;
    sosu.resize(n+1);   //size 조심

    for (int i = 2; i <= n; i++) {
        sosu[i] = i;    // range 조심!
    }

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (sosu[i] == 0)   // 이미 소수가 아닌 수들은 그냥 넘어가주기
            continue;
        for (int j = i * i; j <= n; j += i)
            sosu[j] = 0;
    }
    for (int i = m; i <= n; i++)    // 소수 count
    {
        if (sosu[i] != 0)
            cout<<sosu[i]<<"\n";
    }
    return 0;
}
