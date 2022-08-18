// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int main(){
//     cin.tie(NULL);
//     ios_base::sync_with_stdio(false);

//     int n;
//     cin >> n;
//     vector<int> x(n);
//     vector<int> xCount(n);
//     // 1) input
//     for (int i = 0; i < n; i++) {
//         cin >> x[i];
//     }
//     // 2) counting
//     for (int i = 0; i < n; i++)
//     {
//         vector<int> none;
//         for (int j = 0; j < n; j++)
//         {
//             vector<int>::iterator iter = find(none.begin(),none.end(),x[j]);
//             if(iter != none.end()){
//                 continue;
//             }
//             else if(i!=j && x[i] > x[j]){
//                 // 자기 자신이 아니고, 카운팅된 수가 아니며, 비교대상보다 작다면
//                 none.push_back(x[j]);
//             }
//         }
//         xCount[i] = none.size();
//     }
//     // 3) output
//     for (int i = 0; i < n; i++)
//     {
//         cout<<xCount[i]<<" ";
//     }
//     return 0;
// }