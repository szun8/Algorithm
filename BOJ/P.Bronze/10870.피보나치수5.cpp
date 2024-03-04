#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    int sum = 1;
    vector<int> sums;
    sums.push_back(0);  //n=0
    sums.push_back(1);  //n=1
    for(int i=2;i<=n;i++){
        sum = sums[i-1]+sums[i-2];
        sums.push_back(sum);
    }
    cout<<sums[n];
    return 0;
}