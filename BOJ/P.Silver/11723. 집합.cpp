#include <iostream>
#include <cstring>  // memset
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n,num;
    cin>>n;
    bool set[21]={0, };
    for (int i = 0; i < n; i++)
    {
        string what;
        cin>>what;
        if(what=="add"){
            cin>>num;
            if(!set[num]) set[num]=true; // 없으면(false) 추가
        }
        else if(what=="remove"){
            cin>>num;
            if(set[num]) set[num]=false; // 있으면(true) 삭제
        }
        else if(what=="check"){
            cin>>num;
            if(set[num]) cout<<"1\n";   // 있으면 1
            else    cout<<"0\n";        // 없으면 0
        }
        else if(what=="toggle"){
            cin>>num;
            if(set[num]) set[num]=false;    // 있으면 없게
            else    set[num]=true;          // 없으면 있게 만들아주기
        }
        else if(what=="all"){
            memset(set, true, 21);
        }
        else if(what=="empty"){
            memset(set, false, 21);
        }
    }
    
    return 0;
}