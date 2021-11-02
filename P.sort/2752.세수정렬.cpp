#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> num(3);
    for(int i =0;i<3;i++){
        cin >> num[i];
    }
    sort(num.begin(),num.end());
    for(int i=0;i<3;i++){
        cout<<num[i]<<" ";
    }
    return 0;
}