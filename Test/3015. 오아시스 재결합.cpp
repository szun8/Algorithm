// #include <iostream>
// #include <stack>

// using namespace std;

// int main(){
//     cin.tie(NULL);
//     ios_base::sync_with_stdio(false);

//     int n;
//     cin>>n;
//     int count = 0;
//     stack<long long> Height;
//     stack<long long> Height2;
    
//     for (int i = 0; i < n; i++) {
//         long long height;
//         cin >> height;
//         Height.push(height);
//     }
    
//     for (int i = 0; i < n-1; i++)
//     {
//         Height2 = Height;
//         long long max=0;
//         long long what = Height2.top();   //비교대상
//         Height2.pop();
//         for (int j = i+1; j < n; j++)
//         {
//             if(what < max) break;    // 둘 중 하나라도 작으면 탈출
//             else if(j==i+1|| (max<=Height2.top() && what>=max)){
//                 max = Height2.top();
//                 Height2.pop();
//                 ++count;
//             }
//             else Height2.pop();
//         }
//         Height.pop();
//     }
//     printf("%d",count);
//     return 0;
// }