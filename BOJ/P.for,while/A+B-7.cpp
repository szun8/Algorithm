#include <iostream>
#include <vector>
using namespace std;

int main(){
    int a,b;
    vector<int> sum;
    int input;
    cin >> input;

    for(int i =0;i<input;++i){
        cin>>a;
        cin>>b;
        sum.push_back(a+b);
    }

    for(int i=0;i<sum.size();++i){
        cout<<"Case #"<<i+1<<": "<<sum[i]<<endl;
    }
    return 0;
}