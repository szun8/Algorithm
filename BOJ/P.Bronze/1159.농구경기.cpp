#include <iostream>
#include <set>
#include <map>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    map<char,int> count;
    set<char> first;
    for (int i = 0; i < n; i++)
    {
        string name;
        cin>>name;

        if(count.find(name[0])!=count.end()){
            // 등록된 문자라면, count 증가
            map<char,int>::iterator iter = count.find(name[0]);
            ++(iter->second);
        }
        else{
            // count에 등록된 문자가 아니라면,
            count.insert(pair<char,int>(name[0],1));
        }
    }

    for(map<char,int>::iterator iter = count.begin(); iter != count.end(); ++iter){
        if(iter->second >= 5){
            first.insert(iter->first);
        }
    }
    
    if(first.empty()) cout << "PREDAJA";
    else{
        for(set<char>::iterator iter = first.begin(); iter != first.end(); ++iter){
            cout << *iter;
        }
    }
    return 0;
}