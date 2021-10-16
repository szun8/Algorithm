#include <iostream>
#include <vector>
using namespace std;

int main(){
    int input;
    cin>>input;
    for(int i =0;i<input;++i){
        int num;
        cin >> num;
        string str;
        cin >> str;
        
        for(int j=0;j<str.size();++j){
            for(int z=0; z<num;++z){
                cout<<str[j];
            }
        }
        cout<<endl;
    }
    return 0;
}