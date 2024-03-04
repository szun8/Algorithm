#include <iostream>
#include <vector>
using namespace std;

int main(){
    int a=-1,b=-1;
    vector<int> sum;

    while (a!=0 && b!=0){
        cin >> a;
        cin >> b;
        if(a!=0 && b!=0)
            sum.push_back(a+b);
    }

    for(int i=0; i<sum.size();++i)
        cout<<sum[i]<<endl;

    return 0;
}