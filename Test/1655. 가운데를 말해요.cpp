// #include <iostream>
// #include <queue>
// using namespace std;
// int main(){
//     cin.tie(NULL);
//     ios_base::sync_with_stdio(false);

//     int t; cin>>t;
//     priority_queue<int, vector<int>, greater<int> > left;   // top에 제일 작은 값이 위치
//     priority_queue<int > right;     // top에 가장 큰 값이 위치
//     while (t--) {
//         int n; cin>>n;
//         if(right.empty() || right.top()>n) right.push(n);
//         else if(left.empty() && right.top() < n) left.push(n); 
//         else if(left.top()>=n) right.push(n);
//         else left.push(n);
        
//         if(right.size()%2==1 && left.size()%2==0) cout<<left.top()<<"\n";
//         else cout<<right.top()<<"\n";
//     }
//     return 0;
// }