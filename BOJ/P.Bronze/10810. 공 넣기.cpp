#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N,M,i,j,k; cin>>N>>M;
    vector<int> basket(N+1,0);
    while(M--){
        cin>>i>>j>>k;
        for (int z = i; z <= j; z++) {
            basket[z]=k;
        }
    }
    for (int z = 1; z < N+1; z++){
        cout<<basket[z]<<" ";
    }
    return 0;
}