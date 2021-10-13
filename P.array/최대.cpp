#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int num;
    vector<int> nums;
    for(int i = 0;i<9;++i){
        cin >> num;
        nums.push_back(num);
    }
    int max = *max_element(nums.begin(), nums.end());
    int max_index = max_element(nums.begin(), nums.end())-nums.begin();
    // 반복자 구간에서 최댓값의 주소에서 시작 반복자를 빼주면 최대값 인덱스를 알수있다
    cout << max << endl;
    cout << max_index+1 << endl;
    // 언제나 인덱스는 0에서 시작 = 문제의 조건과 일치하는지 확인
    return 0;
}