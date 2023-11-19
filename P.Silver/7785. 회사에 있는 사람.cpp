#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n; cin>>n;
    unordered_map<string, bool> workers;
    vector<string> result;
    for(int i=0; i<n; i++){
        string name, current;
        cin>>name>>current;
        if(workers[name] && current=="leave"){
            workers[name] = false;
        }
        else{
            workers[name] = true;
        }
    }
    for(unordered_map<string,bool>::iterator iter = workers.begin(); iter!=workers.end(); iter++){
        if(iter->second){
            result.push_back(iter->first);
        }
    }

    sort(result.begin(), result.end(), greater<>());
    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<"\n";
    }
    return 0;
}