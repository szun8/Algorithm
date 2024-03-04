#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    string str;
    cin>>str;
    vector<string> jeopmisa(str.size());
    for (int i = 0; i < str.size(); i++) {
        jeopmisa[i] = str.substr(i);
    }
    sort(jeopmisa.begin(),jeopmisa.end());
    for (int i = 0; i < jeopmisa.size(); i++) {
        cout<<jeopmisa[i]<<"\n";
    }
    
    return 0;
}