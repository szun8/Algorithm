#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n,m,k;
    cin>>n>>m;
    vector<vector<int> > arr(n,vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin>>arr[i][j];
        }
    }
    cin>>k;
    while (k--) {
        int i,j,x,y,sum=0;
        cin>>i>>j>>x>>y;
        for (int a = i-1; a < x; a++){
            for (int b = j-1; b < y; b++){
                sum+=arr[a][b];
            }
        }
        cout<<sum<<"\n";
    }
    return 0;
}