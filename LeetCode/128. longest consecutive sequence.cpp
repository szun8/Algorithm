#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;


// haset set을 사용한 풀이
int longestConsecutive(vector<int>& nums) {
    int answer = 0;
    unordered_set<int> input;

    for(int i=0; i< nums.size();i++){
        input.insert(nums[i]);
    }

    for(auto iter = input.begin() ;iter!=input.end(); iter++){
        int tmp = 0;
        if(input.find((*iter)-1)==input.end()){
            // 시작수가 없음. 현재지점부터 다음을 찾아나가면됨
            tmp++;
            int target = *iter+1; // 시작의 다음수 찾기 시작 
            while(input.find(target)!=input.end()){
                tmp++;
                target++;
            }
        }
        answer = max(answer, tmp);  // 더 큰값으로 갱신
    }
    return answer;
}

int main(){
    vector<int> nums ={100,4,200,1,3,2};
    longestConsecutive(nums);
    return 0;
}