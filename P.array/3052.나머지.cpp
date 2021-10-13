#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int a;
    vector<int> sub;
    for(int i =0;i<10;++i){
        cin>>a;
        sub.push_back(a%42);
    }
    sort(sub.begin(),sub.end());
    sub.erase(unique(sub.begin(),sub.end()),sub.end());
    // vector 중복제거 3요소 : sort, erase, unique
    cout<<sub.size();
    return 0;
}