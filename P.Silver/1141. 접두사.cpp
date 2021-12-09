#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool sortCmp(string a, string b){
    return a.size()<b.size();
}
bool countCmp(bool what){
    return what == false;
}

int main(){
    int n;
    cin>>n;
    int answer = 0;
    vector<string> WORD;
    
    for (int i = 0; i < n; i++)
    {
        string word;
        cin>>word;
        vector<string>::iterator iter = find(WORD.begin(),WORD.end(),word);
        if(iter != WORD.end()) continue;
        else WORD.push_back(word);
    }
    sort(WORD.begin(),WORD.end(),sortCmp);
    vector<bool> notJup(WORD.size());
    fill(notJup.begin(),notJup.end(),false); // 다르면 false, 같으면 true (단 비교자는 처리 x , 피비교자를 true처리하는 구조)
    for (int i = 0; i < WORD.size(); i++)
    {
        for (int j = i+1; j < WORD.size(); j++)
        {
            if(WORD[i][0]==WORD[j][0]){
                string cmpStr = WORD[j].substr(0, WORD[i].size());
                if(cmpStr == WORD[i]) {
                    notJup[i]=true; 
                    break;
                }
            }
        }
    }
    
    cout<<count_if(notJup.begin(),notJup.end(),countCmp);
    return 0;
}