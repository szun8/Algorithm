#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector< pair<char,int> > alpha;
    vector< pair<char,int> >::iterator iter;
    
    for(int i=97; i<123; i++) {
        alpha.push_back(pair<char,int>(i,0));
    }

    string s;
    cin>>s;

    for (int i = 0; i < s.size(); i++)
    {
        for(iter = alpha.begin(); iter != alpha.end(); iter++) {
            if(iter->first==s[i]) {
                iter->second++;
                break;
            }
        }
    }

    for(iter = alpha.begin(); iter != alpha.end(); iter++) {
        cout<<iter->second<<" ";
    }
    return 0;
}