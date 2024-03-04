#include <numeric>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    
    int n, m;
    cin>>n>>m;
    vector<int> nums(n);
    vector<int> sum(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin>>nums[i];
        if(i==0) sum[i] = nums[i];
        sum[i] = nums[i] + sum[i-1];
    }

    for(;m>0;m--){
        int i,j;
        cin>>i>>j;
        if(i==j) printf("%d\n", nums[i-1]);
        else if(i==1) printf("%d\n", sum[j-1]);
        else printf("%d\n", sum[j-1]-sum[i-2]);
    }
    return 0;
}