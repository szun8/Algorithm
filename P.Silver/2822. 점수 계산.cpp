#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int sum=0;
    vector<int> nums;
    vector<pair<int,int> > scores;
    for (int i = 0; i < 8; i++) {
        int score;
        cin>>score;
        scores.push_back(pair<int,int>(score,i+1));
    }
    sort(scores.begin(),scores.end());
    for (int i = 3; i < 8; i++)  sum+=scores[i].first;
    cout<<sum<<"\n";

    for (int i = 3; i < 8; i++) nums.push_back(scores[i].second);
    sort(nums.begin(),nums.end());
    for (int i = 0; i < nums.size(); i++) cout<<nums[i]<<" ";
    return 0;
}