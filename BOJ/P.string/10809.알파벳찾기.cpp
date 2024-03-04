#include<iostream>
using namespace std;

int main(){
    string input;
    int alphabet[26];
    for(int i=0;i<26;++i) alphabet[i]=-1;

    cin >> input;
    for(int i =0;i<input.size();++i){
        if(alphabet[0]==-1&&input[i]=='a') alphabet[0]=i;
        else if(alphabet[1]==-1&&input[i]=='b') alphabet[1]=i;
        else if(alphabet[2]==-1&&input[i]=='c') alphabet[2]=i;
        else if(alphabet[3]==-1&&input[i]=='d') alphabet[3]=i;
        else if(alphabet[4]==-1&&input[i]=='e') alphabet[4]=i;
        else if(alphabet[5]==-1&&input[i]=='f') alphabet[5]=i;
        else if(alphabet[6]==-1&&input[i]=='g') alphabet[6]=i;
        else if(alphabet[7]==-1&&input[i]=='h') alphabet[7]=i;
        else if(alphabet[8]==-1&&input[i]=='i') alphabet[8]=i;
        else if(alphabet[9]==-1&&input[i]=='j') alphabet[9]=i;
        else if(alphabet[10]==-1&&input[i]=='k') alphabet[10]=i;
        else if(alphabet[11]==-1&&input[i]=='l') alphabet[11]=i;
        else if(alphabet[12]==-1&&input[i]=='m') alphabet[12]=i;
        else if(alphabet[13]==-1&&input[i]=='n') alphabet[13]=i;
        else if(alphabet[14]==-1&&input[i]=='o') alphabet[14]=i;
        else if(alphabet[15]==-1&&input[i]=='p') alphabet[15]=i;
        else if(alphabet[16]==-1&&input[i]=='q') alphabet[16]=i;
        else if(alphabet[17]==-1&&input[i]=='r') alphabet[17]=i;
        else if(alphabet[18]==-1&&input[i]=='s') alphabet[18]=i;
        else if(alphabet[19]==-1&&input[i]=='t') alphabet[19]=i;
        else if(alphabet[20]==-1&&input[i]=='u') alphabet[20]=i;
        else if(alphabet[21]==-1&&input[i]=='v') alphabet[21]=i;
        else if(alphabet[22]==-1&&input[i]=='w') alphabet[22]=i;
        else if(alphabet[23]==-1&&input[i]=='x') alphabet[23]=i;
        else if(alphabet[24]==-1&&input[i]=='y') alphabet[24]=i;
        else if(alphabet[25]==-1&&input[i]=='z') alphabet[25]=i;
    }
    for(int i = 0;i<26;++i){
        cout<< alphabet[i] <<" ";
    }
    return 0;
}