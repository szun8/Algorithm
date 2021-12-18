#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
int main(){
    vector<int> minguk(4);
    vector<int> manse(4);
    for (int i = 0; i < 4; i++) cin>>minguk[i];
    for (int i = 0; i < 4; i++) cin>>manse[i];
    int s = accumulate(minguk.begin(),minguk.end(),0);
    int t = accumulate(manse.begin(),manse.end(),0);
    if(s>=t) cout<<s;
    else cout<<t;
    return 0;
}