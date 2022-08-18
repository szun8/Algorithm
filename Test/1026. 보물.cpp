// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <map>
// using namespace std;
// int main(){
//     cin.tie(NULL);
//     ios_base::sync_with_stdio(false);

//     int n, result=0;
//     cin>>n;
//     vector<int> A(n);
//     vector<int> copyA(n);
//     for (int i = 0; i < n; i++) {
//         cin>>A[i];
//     }
//     sort(A.begin(), A.end(), greater<int>());
//     map<int,int> copyB;
//     vector<int> B(n);
//     for (int i = 0; i < n; i++) {
//         cin>>B[i];
//         copyB.insert(pair<int,int>(B[i], i));
//     }
//     int i = 0;
//     for(map<int,int>::iterator iter = copyB.begin(); iter!=copyB.end();++iter){
//         copyA[iter->second]=A[i++];
//     }
//     for (int i = 0; i < n; i++){
//         result += (copyA[i]*B[i]);
//     }
//     cout<<result;
//     return 0;
// }