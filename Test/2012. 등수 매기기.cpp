// #include <iostream>
// #include <queue>
// #include <vector>
// using namespace std;
// int main(){
//     int n; cin>>n;
//     vector<int> howMany(n+1, 0);
//     for (int i = 0; i < n; i++){
//         int num; cin>>num;
//         howMany[num]++;
//     }
//     for (int i = 1; i < howMany.size(); i++)
//     {
//         if(howMany[i]==1) continue;
//         while (howMany[i]>2)
//         {
//             int idx = find(howMany.begin(), howMany.end(), 0)-howMany.begin();
//             --howMany[i];
//         }
        
//     }
    
//     return 0;
// }