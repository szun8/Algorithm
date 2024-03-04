#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    vector<int> sums;
    for (int i = 0; i < 5; i++) {
        int sum=0;
        for (int i = 0; i < 4; i++) {
            int num;
            cin>>num;
            sum+=num;
        }
        sums.push_back(sum);
    }
    cout<<max_element(sums.begin(),sums.end())-sums.begin()+1<<" "<<*max_element(sums.begin(),sums.end());
    return 0;
}