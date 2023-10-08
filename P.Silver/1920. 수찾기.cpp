#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> nums;

bool FindNums(int target){
    int mid, start = 0, end = n-1;

    while(start<=end){
        mid = (start + end) / 2;
        if(nums[mid]==target) return true;
        else if(nums[mid]>target) end = mid - 1; // 원하는 수가 중앙값보다 작으면 end 수정
        else start = mid + 1;   // 원하는 수가 중앙값보다 크면 start 수정
    }
    return false;   // 여기까지 오면 원하는 수가 없는 것으로 판단
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin>>n;
    nums.resize(n);

    for(int i=0; i<n; i++){
        int num; cin>>num;
        nums[i] = num;
    }
    sort(nums.begin(), nums.end()); // 이분탐색을 위한 정렬

    cin>>m;
    for(int i=0;i<m;i++){
        int num; cin>>num;
        printf("%d\n", FindNums(num));
    }
    return 0;
}