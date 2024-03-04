#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int n,l;
    cin>>n>>l;
    int answer=0;
    vector<int> spot(1001);
    fill(spot.begin(),spot.end(),false);
    for (int i = 0; i < n; i++)
    {
        int where;
        cin>>where;
        spot[where]=-1;
    }
    
    while(true){
        vector<int>::iterator iter = find(spot.begin(),spot.end(),-1);
        if(iter!=spot.end()){
            // 찾는 값이 있으면,
            ++answer;
            for (int i = 0; i < l; i++)
            {
                *iter=1;
                ++iter;
            }
        }
        else break;
    }
    cout<<answer;
    return 0;
}