#include <iostream>
#include <numeric>
#include <algorithm>
using namespace std;
int main(){
    int numCount[1001]={0, };
    for(int i=0;i<10;++i)  {
        int what;
        cin>>what;
        ++numCount[what];
    }
    int sum=0;
    for (int i = 0; i < 1001; i++) if(numCount[i]!=0) {
        sum+=(i*numCount[i]);
    }

    cout<<sum/10<<"\n"<<max_element(numCount,numCount+1001)-numCount;
    return 0;
}