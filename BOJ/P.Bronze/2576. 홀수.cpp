#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
int main(){
    vector<int> number;
    for (int i = 0; i < 7; i++)
    {
        int num;
        cin>>num;
        if(num%2==1) number.push_back(num);
    }
    
    int sum = accumulate(number.begin(),number.end(),0);
    int min = *min_element(number.begin(),number.end());
    if(number.empty()) cout<<"-1";
    else cout<<sum<<"\n"<<min;
    return 0;
}