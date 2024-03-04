#include <iostream>
using namespace std;
int main(){
    unsigned long long a,b,c,d;
    cin>>a>>b>>c>>d;

    string ab = to_string(a)+to_string(b);
    string cd = to_string(c)+to_string(d);

    a = stoull(ab);
    c = stoull(cd);
    cout<<a+c;
    return 0;
}