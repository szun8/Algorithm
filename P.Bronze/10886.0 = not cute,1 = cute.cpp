#include <iostream>
using namespace std;
int main(){
    int cute = 0;
    int notcute = 0;
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int ans;
        cin>>ans;
        if(ans==1) cute++;
        else notcute++;
    }

    if(cute>notcute) cout<<"Junhee is cute!";
    else cout <<"Junhee is not cute!";
    
    return 0;
}