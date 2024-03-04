#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n,k;
    cin>>n>>k;

    vector<int> num(n);
    for (int i = 0; i < n; i++)
    {
        cin>>num[i];
    }
    nth_element(num.begin(),num.begin()+k-1,num.end());
    
    cout<<num[k-1];
    
    return 0;
}