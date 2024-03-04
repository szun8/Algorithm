#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool isbig (string a, string b){
    if(a.size()==b.size()) return a<b;  // 크기가 같으면, 사전순으로 
    else return a.size()<b.size();      // 크키가 다르면, 오름차순으로
}
int main(){
    int n;
    cin>>n;
    vector<string> word(n);
    for (int i = 0; i < n; i++) {
        cin>>word[i];
    }
    sort(word.begin(),word.end(),isbig);
    word.erase(unique(word.begin(),word.end()),word.end()); //중복제거

    for (int i = 0; i < word.size(); i++)
    {
        cout<<word[i]<<endl;
    }    
    return 0;
}