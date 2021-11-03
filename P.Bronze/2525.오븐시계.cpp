#include <iostream>
using namespace std;

int main(){
    int a,b,c;
    cin >>a>>b;
    cin >>c;

    int hour=a, min=b+c;
    if(b+c>=60){
        int count=0;
        while(min>=60){
            min-=60;
            count++;
        }
        hour+=count;
        if(hour>=24) hour-=24;
    }
    else {
        min = b+c;
    }
    cout<<hour<<" "<<min;
    return 0;
}