#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    string a,b;
    for(int i =0;i<n;i++){
        getline(cin,a,',');
        getline(cin,b);
        int A=stoi(a);
        int B=stoi(b);
        cout<<A+B<<endl;
    }
    return 0;
}