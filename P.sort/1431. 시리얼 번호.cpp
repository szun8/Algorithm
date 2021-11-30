#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(string a, string b){
    if(a.size()!=b.size()) return a.size()<b.size();

    int anum=0, bnum=0;
    for (int i = 0; i < a.size(); i++)
    {
        if(a[i]<=57 && a[i]>=48){
            anum+=(a[i]-'0');
        }
        if(b[i]<=57 && b[i]>=48){
            bnum+=(b[i]-'0');
        }
    }

    if(anum!=bnum) return anum<bnum;
    else return a<b;
}

int main(){
    int n;
    cin>>n;
    vector<string> serial(n);
    for (int i = 0; i < n; i++) {
        cin>>serial[i];
    }
    stable_sort(serial.begin(),serial.end(),cmp);
    for (int i = 0; i < n; i++) {
        cout<<serial[i]<<"\n";
    }
    return 0;
}