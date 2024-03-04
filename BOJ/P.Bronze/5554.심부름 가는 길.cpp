#include <iostream>
using namespace std;
int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int time = a+b+c+d;
    int minute = time/60;
    int sec = time%60;
    cout<<minute<<endl<<sec;
    return 0;
}