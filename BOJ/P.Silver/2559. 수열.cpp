#include <iostream>
#include <vector>

using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n,k;
    cin>>n>>k;

    vector<int> degree(n);
    for(int i=0; i<n; i++){
        cin>>degree[i];
    }

    vector<int> prefixSum(n-k+1, 0);
    for(int i=0; i<k; i++){
        prefixSum[0] += degree[i];
    }
    int max = prefixSum[0];

    for(int i=1;i<n-k+1; i++){
        prefixSum[i] = prefixSum[i-1] - degree[i-1] + degree[i-1+k];
        if(max < prefixSum[i]) max = prefixSum[i];
    }

    printf("%d", max);

    return 0;
}