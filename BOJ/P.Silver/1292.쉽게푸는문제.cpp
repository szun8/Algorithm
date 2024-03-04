#include <iostream>
#include <vector>
using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    int sum=0;
    int total=0;
    vector<int> num;
    for(int i=1;total<=b;i++){
        int count=0;
        while(count<i){
            num.push_back(i);
            ++count;
            ++total;
        }
    }
    for(int i=a-1;i<b;++i){
        sum+=num[i];
    }
    cout<<sum;
    return 0;
}