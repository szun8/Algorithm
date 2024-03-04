#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> num(3);
    vector<int> count(6);
    for(int i=0;i<3;++i){
        cin>>num[i];
        count[num[i]-1]++;
    }
    sort(num.begin(),num.end(),greater<int>());

    int money=0;
    if(find(count.begin(),count.end(),3)!=count.end()) money=10000+(num[0]*1000);
    else if (find(count.begin(),count.end(),2)!=count.end())  {
        for(int i=0;i<6;++i){
            if(count[i]==2) {
                money=1000+((i+1)*100);
                break;
            }
        }
    }
    else {
        money=num[0]*100;
    }
    cout<<money;
    return 0;
}