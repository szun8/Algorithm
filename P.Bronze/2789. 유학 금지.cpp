#include <iostream>
using namespace std;
int main(){
    //  CAMBRIDGE
    string word;
    cin>>word;
    string newWord="";
    for (int i = 0; i < word.size(); i++)
    {
        if(word[i]=='C' || word[i]=='A' || word[i]=='M' || word[i]=='B') continue;
        else if(word[i]=='R' || word[i]=='I' || word[i]=='D' || word[i]=='G' || word[i]=='E') continue;
        else newWord.push_back(word[i]);
    }
    cout<<newWord;
    return 0;
}