#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int ans = 0;
    int arr[5]={0, };
    for (int i = 0; i < 5; i++)
    {
        cin>>arr[i];
        if(n==arr[i]) ++ans;
    }
    cout<<ans;
    return 0;
}
