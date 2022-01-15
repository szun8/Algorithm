#include <iostream>
using namespace std;
int main(){
    int t; cin>>t;
    while (t--) {
        int n; cin>>n;
        int p1=0,p2=0;
        while (n--) {
            char P1,P2; cin>>P1>>P2;
            if(P1=='R'){
                if(P2=='S') p1++;
                else if(P2=='P') p2++;
            }
            else if(P1=='S'){
                if(P2=='P') p1++;
                else if(P2=='R') p2++;
            }
            else if(P1=='P'){
                if(P2=='R') p1++;
                else if(P2=='S') p2++;
            }
        }

        if(p1>p2) cout<<"Player 1\n";
        else if(p1<p2) cout<<"Player 2\n";
        else cout<<"TIE\n";
    }
    return 0;
}