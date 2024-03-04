#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
int main(){
    vector<int> heights(9);
    for (int i = 0; i < 9; i++) {
        cin>>heights[i];
    }
    
    int sum = accumulate(heights.begin(),heights.end(),0);
    int sub,tmp1,tmp2;
    for (int i = 0; i < 9; i++) {
        for (int j = i+1; j < 9; j++) {
            sub = heights[i]+heights[j];
            if(sum - sub == 100) {
                tmp1 = i;
                tmp2 = j;
                i=9;
                break;
            }
        }
    }

    for (int z = 0; z < 9; z++) {
        if(z == tmp1 || z == tmp2) continue;
        else {
            cout<<heights[z]<<"\n";
        }
    }
    return 0;
}