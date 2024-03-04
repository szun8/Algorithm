#include <iostream>
using namespace std;
int main(){
    int stu[30]={0, };
    for(int i=0;i<28;i++){
        int n;
        cin>>n;
        stu[n-1]=1;
    }
    for (int i = 0; i < 30; i++)
    {
        if(stu[i]==0) cout<<i+1<<endl;
    }
    return 0;
}