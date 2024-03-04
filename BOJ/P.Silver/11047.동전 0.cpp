#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n,k;
    cin >> n >> k;
    int count = 0;
    vector<int> value(n);
    for(int i=0;i<n;++i){
        cin>>value[i];
    }
    // 항상 최소 조건을 생각하자!
    for (int i = n-1; k>0 && i>=0; i--)
    {
        if(value[i]<=k){
            k-=value[i];
            ++i;
            ++count;
        }
    }
    cout<<count;
    return 0;
}