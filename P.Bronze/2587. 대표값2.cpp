#include <iostream>
#include <numeric>
#include <algorithm>
using namespace std;
int main(){
    int num[5];
    for(int i=0;i<5;++i)  cin>>num[i];
    int p = accumulate(num,num+5,0)/5;
    sort(num,num+5);
    cout<<p<<"\n"<<num[2];
    return 0;
}