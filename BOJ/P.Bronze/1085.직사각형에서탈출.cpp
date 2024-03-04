#include <iostream>
#include <algorithm>
using namespace std;

int main(){

    int x,y,w,h;
    cin>>x>>y>>w>>h;
    int xtow = w-x;
    int ytoh = h-y;

    int big[4]={x,y,xtow,ytoh};

    cout << *min_element(big,big+4);
    return 0;
}