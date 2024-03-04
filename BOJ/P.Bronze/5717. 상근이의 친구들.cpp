#include <iostream>
using namespace std;
int main(){
    int m,f;
    while(true){
        cin>>m>>f;
        if(m==0&&f==0) break;
        else cout<<m+f<<endl;
    }
    return 0;
}