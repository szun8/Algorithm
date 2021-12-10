#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;

    int answer = 0;
    vector<bool> pc(100);
    fill(pc.begin(),pc.end(),false);
    for (int i = 0; i < n; i++)
    {
        int num;
        cin>>num;
        if(pc[num-1]==true) ++answer;
        else pc[num-1]=true;
    }
    cout<<answer;
    return 0;
}