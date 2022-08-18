// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int main(){
//     int n,m;
//     cin>>n>>m;
//     vector<int> trees;
//     for(int i=0;i<n;++i){
//         int tree;
//         cin>>tree;
//         trees.push_back(tree);
//     }
    
//     if(n==1){
//         cout << trees[0] - m;
// 		return 0;
//     }
//     int min, max = *max_element(trees.begin(),trees.end());
//     if(*min_element(trees.begin(),trees.end())<=m)   min = *min_element(trees.begin(),trees.end());
//     else min= *min_element(trees.begin(),trees.end()) - m;
    
//     unsigned int low=0, high=max, mid;
//     vector<long long> sums;
//     while(true){
//         long long int sum=0;
//         vector<int> temp;
//         for(int i =0;i<trees.size();++i){
//             temp.push_back(trees[i]);
//         }
//         if(low<=high){
//             mid = (low+high)/2;
//             for(int i=0;i<trees.size();++i){
//                 temp[i]-=mid;
//                 if(temp[i]<=0) temp[i]=0;
//                 sum+=temp[i];
//             }
//             if(sum == m){   // 원하는 값이라면,s
//                 cout<<mid;
//                 break;
//             }
//             else if(sum > m){
//                 sums.push_back(mid);
//                 low=mid+1;
//             }
//             else high = mid-1;
//         }
//         else{
//             if(m>*max_element(trees.begin(),trees.end()))
//                 cout<< *min_element(sums.begin(),sums.end());
//             else
//                 cout<< *max_element(sums.begin(),sums.end());

//             break;
//         }
//     }
//     return 0;
// }