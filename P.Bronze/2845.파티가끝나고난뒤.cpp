#include <iostream>
using namespace std;
int main(){
    int l,p;
    cin >>l>>p;
    int mul=l*p;
    int news[5]={0, };
    for(int i =0;i<5;i++){
        cin >> news[i];
        int n=0;
        if(mul != news[i]){
            n = news[i]-mul;
            
        }
        cout<<n<<" ";
    }

    return 0;
}