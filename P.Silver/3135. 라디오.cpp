#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main(){
    int a,b;
    cin>>a>>b;

    int n;
    cin>>n;
    vector<int> like(n);
    for (int i = 0; i < n; i++) {
        cin>>like[i];
    }
    int sub = abs(a-b);
    
    if(find(like.begin(),like.end(),b)!=like.end()){
        // 즐겨찾기 중에 원하는 주파수가 있다면 바로 달려가기
        cout<<"1";
        return 0;
    }
    
    int fav=999;
    for (int i = 0; i < like.size(); i++) {
        int what = abs(b-like[i]);
        if(what<fav) fav = what;
    }

    if(fav+1<sub) cout<<fav+1;
    else cout<<sub;
    return 0;
}