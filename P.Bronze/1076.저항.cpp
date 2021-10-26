#include <iostream>
using namespace std;

int main(){
    string color[3];
    for(int i =0;i<3;++i){
        cin >> color[i];
    }
    int black[3]={0,0,1};   // 초기화 갯수만큼 잘해주자..^^
    int brown[3]={10,1,10};
    int red[3]={20,2,100};
    int orange[3]={30,3,1000};
    int yellow[3]={40,4,10000};
    int green[3]={50,5,100000};
    int blue[3]={60,6,1000000};
    int violet[3]={70,7,10000000};
    unsigned long long grey[3]={80,8,100000000};
    unsigned long long white[3]={90,9,1000000000};

    unsigned long long sum=0;
    
    if(color[0]=="black") sum+=black[0];
    else if(color[0]=="brown") sum+=brown[0];
    else if(color[0]=="red") sum+=red[0];
    else if(color[0]=="orange") sum+=orange[0];
    else if(color[0]=="yellow") sum+=yellow[0];
    else if(color[0]=="green") sum+=green[0];
    else if(color[0]=="blue") sum+=blue[0];
    else if(color[0]=="violet") sum+=violet[0];
    else if(color[0]=="grey") sum+=grey[0];
    else if(color[0]=="white") sum+=white[0];

    if(color[1]=="black") sum+=black[1];
    else if(color[1]=="brown") sum+=brown[1];
    else if(color[1]=="red") sum+=red[1];
    else if(color[1]=="orange") sum+=orange[1];
    else if(color[1]=="yellow") sum+=yellow[1];
    else if(color[1]=="green") sum+=green[1];
    else if(color[1]=="blue") sum+=blue[1];
    else if(color[1]=="violet") sum+=violet[1];
    else if(color[1]=="grey") sum+=grey[1];
    else if(color[1]=="white") sum+=white[1];

    if(color[2]=="black") sum*=black[2];
    else if(color[2]=="brown") sum*=brown[2];
    else if(color[2]=="red") sum*=red[2];
    else if(color[2]=="orange") sum*=orange[2];
    else if(color[2]=="yellow") sum*=yellow[2];
    else if(color[2]=="green") sum*=green[2];
    else if(color[2]=="blue") sum*=blue[2];
    else if(color[2]=="violet") sum*=violet[2];
    else if(color[2]=="grey") sum*=grey[2];
    else if(color[2]=="white") sum*=white[2];

    cout<<sum;
    return 0;
}