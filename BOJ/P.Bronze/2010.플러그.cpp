#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n; //멀티탭 갯수
    vector<int> num(n);
    int count=0;
    for (int i = 0; i < n; i++)
    {
        cin>>num[i];
        count+=num[i];
    }

    cout<< count-(n-1);
    
    return 0;
}