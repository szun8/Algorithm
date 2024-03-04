#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    int n;
    cin>>n;
    vector<int> Sort(n);
    for (int i = 0; i < n; i++) cin>>Sort[i];
    sort(Sort.begin(),Sort.end(),cmp);
    //sort(Sort.begin(),Sort.end(),greater<int>()); - 내림차순
    for (int i = 0; i < n; i++) cout<<Sort[i]<<"\n";
    return 0;
}