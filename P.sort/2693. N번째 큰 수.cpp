#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        vector<int> nums(10);
        for (int j = 0; j < 10; j++)
        {
            cin>>nums[j];
        }
        sort(nums.begin(),nums.end());
        cout<<nums[7]<<"\n";
    }
    return 0;
}