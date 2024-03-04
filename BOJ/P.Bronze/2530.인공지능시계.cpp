#include <iostream>
using namespace std;

int main(){
    int a,b,c,d;
    cin >>a>>b>>c;  //시 분 초
    cin >>d;        //필요한 시계

    int minute = d/60;
    int second = d%60;

    c+=second;
    if(c>=60){
        b++;
        c=c-60;
    }

    b+=minute;
    if(b>=60){
        a=a+(b/60);
        b=b%60;
    }

    if(a>=24){
        a=a%24;
    }

    cout << a << " " << b <<" " << c;

    return 0;
}