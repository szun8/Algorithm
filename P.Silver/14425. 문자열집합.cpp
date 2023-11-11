#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n, m; cin>>n>>m;
    unordered_map<string, bool> s;
    int cnt = 0;
    for(int i =0; i<n; i++){
        string str;
        cin>>str;
        s[str] = true;
    }

    for(int i =0;i<m;i++){
        string str;
        cin>>str;
        if(s[str]) ++cnt;
    }

    printf("%d", cnt);
    return 0;
}