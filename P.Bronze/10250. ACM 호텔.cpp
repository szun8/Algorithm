#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int t;
    cin>>t;
    for (int i = 0; i < t; i++)
    {
        int h,w,n,floor, num;
        cin>>h>>w>>n;

        if(n%h==0) floor = h;
        else floor = n%h;
        num = ceil((float)n/h);

        if(num<10){
            cout<<floor<<"0"<<num<<"\n";
        }
        else{
            cout<<floor<<num<<"\n";
        }
    }
    
    return 0;
}