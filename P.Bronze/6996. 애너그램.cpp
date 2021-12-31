#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int t; cin>>t;
    while (t--) {
        string a,b,tmpA,tmpB;
        cin>>a>>b;
        tmpA=a, tmpB=b;
        if(a.size()!=b.size()) {
            cout<<tmpA<<" & "<<tmpB<<" are NOT anagrams.\n";
        }
        else{
            int cnt=0;
            for (int i = 0; i < b.size(); i++) {
                for (int j = 0; j < a.size(); j++) {
                    if(b[i]==a[j]){
                        a[j]='.';
                        ++cnt;
                        break;
                    }
                }
            }
            cnt==b.size() ? cout<<tmpA<<" & "<<tmpB<<" are anagrams.\n" : cout<<tmpA<<" & "<<tmpB<<" are NOT anagrams.\n";
        }
    }
    return 0;
}