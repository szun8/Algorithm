#include <iostream>
using namespace std;

int main(){
    int count = 0;
    for(int i =0;i<8;i++){
        string chess;
        getline(cin,chess);

        for(int j=0;j<chess.size();++j){
            if(i%2==0 && j%2==0 && chess[j]=='F'){
                ++count;
            }
            else if(i%2==1 && j%2==1 && chess[j]=='F'){
                ++count;
            }
        }
    }
    cout << count;
    return 0;
}