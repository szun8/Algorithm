#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(pair<string, int> a, pair<string, int> b){
    if(a.second!=b.second) return a.second>b.second;
    else return a.first<b.first;
}
int main() {
    int n;
    cin>>n;
    vector< pair<string, int> > book;
    for (int i = 0; i < n; i++)
    {
        string name;
        cin>>name;
        bool isHere = false;
        for (int j = 0; j < book.size(); j++)
        {
            if(book[j].first == name) {
                isHere = true;
                book[j].second++;
                break;
            }
        }
        
        if(isHere == false){
             book.push_back(pair<string, int>(name,1));
        }
    }
    sort(book.begin(),book.end(),cmp);
    cout<<book[0].first;
    return 0;
}