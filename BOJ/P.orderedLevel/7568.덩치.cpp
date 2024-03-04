#include <iostream>
#include <vector>
using namespace std;

int main(){
    int input;
    cin>>input;
    vector< vector<int> > big(input);
    for(int i=0;i<input;++i){
        int x,y;
        cin>>x>>y;
        big[i].push_back(x);    // [0]
        big[i].push_back(y);    // [1]
        big[i].push_back(1);    // [2]
    }

    for(int i=0;i<input;++i){
        for(int j=0;j<input;++j){
            if(i!=j && big[i][0]<big[j][0] && big[i][1]<big[j][1]){
                ++big[i][2];
            }
        }
    }

    for(int i = 0;i<input;++i){
        cout<<big[i][2]<<" ";
    }
    return 0;
}