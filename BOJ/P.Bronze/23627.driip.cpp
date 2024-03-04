#include <iostream>
using namespace std;
int main(){
    string input;
    cin>>input;
    string driip = "piird";
    int size = input.size()-1;
    bool isdriip = true;
    for(int i = 4 ; i>=0 ; i--){
        if(input[size-i]!=driip[i]) {
            isdriip = false;
            break;
        }
    }
    if(isdriip == true) cout<<"cute";
    else cout<<"not cute";
    return 0;
}