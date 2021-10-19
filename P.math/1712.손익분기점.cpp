#include <iostream>
using namespace std;

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    int count=1;
    long long cost = a + (b*count);
    long long benefit = c*count;
    if(b>=c) count=-1;
    else {
        count = a/(c-b)+1;
    }
    
    cout << count;
    return 0;
}