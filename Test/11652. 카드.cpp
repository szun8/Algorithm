// #include <iostream>
// #include <algorithm>
// #include <vector>
// using namespace std;

// int main(){
//     cin.tie(NULL);
//     ios_base::sync_with_stdio(false);

//     int n;
//     cin>>n;
//     vector<long long> nums;
//     vector<int> counts;
//     for (int i = 0; i < n; i++)
//     {
//         long long what;
//         cin>>what;
//         vector<long long>::iterator iter = find(nums.begin(),nums.end(),what);
//         if(iter!=nums.end()) ++counts[iter-nums.begin()];
//         else{
//             nums.push_back(what);
//             counts.push_back(1);
//         } 
//     }

//     int max = *max_element(counts.begin(),counts.end());
//     int maxCount = 0;
//     for (int i = 0; i < counts.size(); i++)
//     {
//         if(counts[i]==max) ++maxCount;
//     }
    
//     if (maxCount == 1)
//     {
//         int index = max_element(counts.begin(),counts.end())-counts.begin();
//         cout<<nums[index];
//     }
//     else{
//         // 여러개라면, 제일 작은 수를 출력
//         vector<long long> maxNums;
//         for (int i = 0; i < nums.size(); i++) {
//             if(counts[i]==max) maxNums.push_back(nums[i]);
//         }
        
//         sort(maxNums.begin(),maxNums.end());
//         cout<<maxNums[0];
//     }
//     return 0;
// }

// vector<string> nums;
//     vector<int> count;
    
//     for (int i = 0; i < n; i++)
//     {
//         string num;
//         cin>>num;
//         vector<string>::iterator iter = find(nums.begin(),nums.end(),num);
//         if(iter!=nums.end()) ++count[iter-nums.begin()];
//         else {
//             nums.push_back(num);
//             count.push_back(1);
//         }
//     }
    
//     int maxCount=0;
//     int Max = *max_element(count.begin(),count.end());
//     for (int i = 0; i < count.size(); i++) {
//         if(count[i]==Max) ++maxCount;
//     }
    
//     if(maxCount==1){
//         int index = max_element(count.begin(),count.end())-count.begin();
//         cout<<nums[index];
//     }
//     else{
//         // 여러개라면, 제일 작은 수를 출력
//         vector<string> maxNums;
//         for (int i = 0; i < nums.size(); i++) {
//             if(count[i]==Max) maxNums.push_back(nums[i]);
//         }
        
//         sort(maxNums.begin(),maxNums.end());
//         string arr = "-";
//         if(maxNums[0][0]=='-'){
//             int where = find_end(maxNums.begin(),maxNums.end(),arr.begin(),arr.begin()+1)-maxNums.begin();
//             cout<<maxNums[where];
//         }
//     }