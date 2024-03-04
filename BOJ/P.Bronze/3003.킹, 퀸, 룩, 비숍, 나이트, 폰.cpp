#include <iostream>
using namespace std;

int main(){
    int chess[6]={0, };
    int correctChess[6]={1,1,2,2,2,8};
    for(int i=0;i<6;i++){
        cin>>chess[i];
        if(chess[i]!=correctChess[i])
            chess[i] = (correctChess[i] - chess[i]);
        else
            chess[i] = 0;
    }

    for(int i=0;i<6;i++){
        cout<<chess[i]<<" ";
    }
    return 0;
}