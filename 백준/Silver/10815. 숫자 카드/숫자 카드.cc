#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n; cin>>n;
    map<int, bool> card;

    for(int i=0; i<n; i++){
        int num; cin>>num;
        card[num] = true;
    }

    int m; cin>>m;
    for (int i = 0; i < m; i++)
    {
        int exist; cin>>exist;
        if(card[exist]){
            cout<<"1 ";
        }
        else cout<<"0 ";
    }
    
    return 0;
}