#include<iostream>
using namespace std;

int main(){
    string input;
    cin>>input;
    // 2(ABC)=3s, 3(DEF)=4s, 4(GHI)=5s, 5(JKL)=6s, 6(MNO)=7s, 7(PQRS)=8s, 8(TUV)=9s, 9(WXYZ)=10s
    int time=0;
    for(int i = 0;i<input.size();++i){
        if(input[i]=='A'||input[i]=='B'||input[i]=='C') time+=3;
        else if(input[i]=='D'||input[i]=='E'||input[i]=='F') time+=4;
        else if(input[i]=='G'||input[i]=='H'||input[i]=='I') time+=5;
        else if(input[i]=='J'||input[i]=='K'||input[i]=='L') time+=6;
        else if(input[i]=='M'||input[i]=='N'||input[i]=='O') time+=7;
        else if(input[i]=='P'||input[i]=='Q'||input[i]=='R'||input[i]=='S') time+=8;
        else if(input[i]=='T'||input[i]=='U'||input[i]=='V') time+=9;
        else if(input[i]=='W'||input[i]=='X'||input[i]=='Y'||input[i]=='Z') time+=10;
    }
    cout<<time;
    return 0;
}