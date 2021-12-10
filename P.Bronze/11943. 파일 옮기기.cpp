#include <iostream>
using namespace std;
int main(){
    int a,b,c,d;
    cin>>a>>b;
    cin>>c>>d;
    int answer = 0;
    if(a>c) answer = c;
    else answer = a;

    if(b>d) answer+=d;
    else answer+=b;

    cout<<answer; 
    return 0;
}