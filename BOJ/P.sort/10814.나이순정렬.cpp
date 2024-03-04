#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool naming(pair<int, string> a, pair<int, string> b){
    return a.first<b.first;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n;
    cin>>n;

    vector< pair<int, string> > member;
    for (int i = 0; i < n; i++){
        int age;
        string name;
        cin >> age >> name;
        member.push_back(pair<int, string>(age, name));
    }
    stable_sort(member.begin(),member.end(),naming);
    for (int i = 0; i < n; i++)
    {
        cout<<member[i].first<<" "<<member[i].second<<"\n";
    }
    
    return 0;
}