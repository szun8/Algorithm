#include <iostream>
using namespace std;

int main(){
    int h, m;
    cin >> h;
    cin >> m;

    if(m >= 45){
        m-=45;
    }
    else{
        m+=15; // +60, -45
        if(h==0) h=23;
        else h-=1;
    }
    cout << h << " " << m << endl;
    return 0;
}