#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int a,b,c,d;
    cin>>a>>b;
    cin>>c>>d;
    int answer1 = a+d;
    int answer2 = b+c;
    
    cout<<min(answer1,answer2);
    return 0;
}