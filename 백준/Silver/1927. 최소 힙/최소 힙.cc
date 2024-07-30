#include <iostream>
#include <queue>
using namespace std;

#define ll long long

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n; cin>>n;
    priority_queue<ll,vector<ll>, greater<ll> > pq;
    while (n--) {
        ll what; cin>>what;
        if(what==0){
            if(pq.empty()) cout<<0<<"\n";
            else {
                cout<<pq.top()<<"\n";
                pq.pop();
            }
        }
        else pq.push(what);
    }
    return 0;
}