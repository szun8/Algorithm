#include <iostream>
#include <unordered_map>
using namespace std;

// 같은 key가 삽입될 수도 있다는 점에서 그냥 unoreder_map이 아닌 unordered_multimap을 사용해야함
// 해당 자료구조의 삽인은 operator[]가 아니라 insert() 함수를 사용해줘야 삽입이 가능해짐.

vector<int> twoSum(vector<int>& nums, int target) {

    unordered_multimap<int, int> dict; // key : 숫자, value : nums의 index
    vector<int> answer;

    for(int i=0; i<nums.size(); i++){
        dict.insert({nums[i], i}); // num, index -> 같은 num에 대해서는 index로 분간.
    }
    for(int i=0; i<nums.size();i++){
        vector<int> temp;
        temp.push_back(i);
        int needed_num = target - nums[i];

        auto iter_need = dict.find(needed_num);

        if(iter_need != dict.end() && i - iter_need->second != 0){ 
            temp.push_back(iter_need->second); // 해당 숫자의 인덱스를 넣어준다.
            return temp;
        }
    }

    return answer;
}

int main(){
    vector<int> nums = {3,3};
    vector<int> answer = twoSum(nums, 6);
    return 0;
}