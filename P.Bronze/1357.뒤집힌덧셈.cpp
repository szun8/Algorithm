#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    string x,y;
    cin >> x >> y;

    reverse(x.begin(),x.end());
    reverse(y.begin(),y.end());

    int X = stoi(x);
    int Y = stoi(y);

    int num = X+Y;
    x=to_string(num);
    reverse(x.begin(),x.end());
    cout<<stoi(x);
    return 0;
}