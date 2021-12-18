#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n, what;
    cin>>n;
    vector<int> number(n);
    for (int i = 0; i < n; i++)  cin>>number[i];
    cin>>what;
    cout<<count(number.begin(),number.end(),what);
    return 0;
}