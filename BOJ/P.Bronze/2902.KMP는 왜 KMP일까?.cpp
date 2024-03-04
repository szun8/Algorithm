#include <iostream>
using namespace std;

int main(){
    string kmp;
    cin>>kmp;
    for (int i = 0; i < kmp.size(); i++)
    {
        if(kmp[i]>=65 && kmp[i]<=90) cout<<kmp[i];
    }
    
    return 0;
}