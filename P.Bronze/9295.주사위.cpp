#include <iostream>
using namespace std;

int main(){
    int input;
    cin >> input;
    for(int i=0;i<input;++i){
        int a,b;
        cin >> a >> b;
        cout << "Case " << i << ": " << a+b<<endl;
    }
    return 0;
}