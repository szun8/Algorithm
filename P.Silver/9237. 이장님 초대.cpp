#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int> tree(n);
    for (int i = 0; i < n; i++) cin>>tree[i];
    sort(tree.begin(),tree.end(),greater<int>());   // 오름차순
    for (int i = 0; i < n; i++) tree[i]+=(i+1);
    cout<<*max_element(tree.begin(),tree.end())+1;
    return 0;
}