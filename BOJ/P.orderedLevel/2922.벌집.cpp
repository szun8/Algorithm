#include <iostream>
using namespace std;

int main(){
    int n,num=1;
    int room=0;
    cin >> n;
    for(int i = 1; num < n;++i){
        num += (i * 6);
        room = i;
        if(num>n) break;
    }

    cout<<room+1;
    return 0;
}
