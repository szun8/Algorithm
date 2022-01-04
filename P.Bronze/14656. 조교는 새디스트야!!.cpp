#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, cnt=0; cin>>n;
    vector<int> line(n);
    for (int i = 0; i < n; i++){
        cin>>line[i];
        if(line[i]!=i+1) ++cnt;
    }
    cout<<cnt;
    return 0;
}