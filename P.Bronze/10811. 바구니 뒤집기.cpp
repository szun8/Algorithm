#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N,M; cin>>N>>M;
    vector<int> basket(N+1);
    for (int i = 0; i < N+1; i++) basket[i]=i;
    
    while(M--){
        int i,j; cin>>i>>j;
        vector<int> temp;
        for (int k = i; k <=j; k++) {
            temp.push_back(basket[k]);
        }
        for (int k = i; k <=j; k++) {
            basket[k]=temp.back();
            temp.pop_back();
        }
    }
    for (int i = 1; i < N+1; i++) cout<<basket[i]<<" ";
    
    return 0;
}