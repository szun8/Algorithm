#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin>>n>>m;
    vector<string> twin;
    map<string, int> people;
    for(int i=0; i<n;i++){
        string name;
        cin>>name;
        people.insert(make_pair(name,1));
    }

    for(int i=0; i<m;i++){
        string name;
        cin>>name;
        if(people[name]==1){
            twin.push_back(name);
        }
        else{
            people.insert(make_pair(name,1));
        }
    }

    // output-------------------
    sort(twin.begin(), twin.end()); // 사전순 출력
    cout<<twin.size()<<"\n";
    for(int i=0; i<twin.size();i++){
        cout<<twin[i]<<"\n";
    }
    return 0;
}