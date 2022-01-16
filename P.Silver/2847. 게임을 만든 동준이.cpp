#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n,how=0; cin>>n;
    vector<int> num(n);
    for (int i = 0; i < n; i++){
        cin>>num[i];
    }
    for (int i = n-2; i >= 0; --i){
        while(num[i]>=num[i+1]) {
            num[i]--; how++;
        }
    }
    cout<<how;
    return 0;
}