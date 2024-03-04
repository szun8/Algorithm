#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> price(n);
    for (int i = 0; i < n; i++)
    {
        cin>>price[i];
    }
    sort(price.begin(),price.end(),greater<int>());

    int cost = 0;
    for (int i = 0; i < n; i++)
    {
        if((i+1)%3==0) continue;
        else cost+=price[i];
    }
    cout<<cost;
    return 0;
}