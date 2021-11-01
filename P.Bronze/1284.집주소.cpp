#include <iostream>
using namespace std;

int main(){
    while(true){
        string num;
        cin >> num;
        if(num=="0\0") return 0;
        int count = 1;
        for(int i =0;i<num.size();i++){
            if(num[i]=='0') count+=4;
            else if (num[i]=='1') count+=2;
            else {
                count+=3;
            }
            ++count;
        }
        cout<<count<<endl;
    }
    return 0;
}