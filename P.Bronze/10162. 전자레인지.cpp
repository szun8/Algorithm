#include <iostream>
using namespace std;
int main(){
    int time;
    cin>> time;
    int a=0,b=0,c=0;
    if(time%10!=0){
        cout<<-1;
        return 0;
    }
    while(time>0){
        if(time>=300){
            ++a;
            time-=300;
        }
        else if(time>=60){
            ++b;
            time-=60;
        }
        else if(time>=10){
            ++c;
            time-=10;
        }
        else{
            cout<<-1;
            return 0;
        }
    }
    cout<<a<<" "<<b<<" "<<c;
    return 0;
}