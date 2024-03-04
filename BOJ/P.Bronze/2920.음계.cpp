#include <iostream>
#include <vector>
using namespace std;

int main(){
    bool isum = true;
    vector<int> um(8);
    for(int i=0;i<8;i++){
        cin>>um[i];
    }
    if(um[0]==1){
        for(int i=1;i<8;i++){
            if(um[i]!=i+1) {
                isum = false;
                break;
            }
        }
        if(isum==true) cout<<"ascending";
        else cout<<"mixed";
    }
    else if(um[0]==8){
        int j=7;
        for(int i=1;i<8;i++){
            if(um[i]!=j) {
                isum = false;
                break;
            }
            --j;
        }

        if(isum==true) cout<<"descending";
        else cout<<"mixed";
    }
    else cout<<"mixed";
    return 0;
}