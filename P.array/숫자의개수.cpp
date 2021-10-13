#include <iostream>
#include <string>
using namespace std;

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    
    int num_size[10]={0, };
    int mul = a*b*c;
    string str_mul = to_string(mul);
    for(int i = 0 ;i < str_mul.size() ;++i){
        if(str_mul[i]=='0') ++num_size[0];
        else if(str_mul[i]=='1') ++num_size[1];
        else if(str_mul[i]=='2') ++num_size[2];
        else if(str_mul[i]=='3') ++num_size[3];
        else if(str_mul[i]=='4') ++num_size[4];
        else if(str_mul[i]=='5') ++num_size[5];
        else if(str_mul[i]=='6') ++num_size[6];
        else if(str_mul[i]=='7') ++num_size[7];
        else if(str_mul[i]=='8') ++num_size[8];
        else if(str_mul[i]=='9') ++num_size[9];
    }
    for(int i=0;i<10;++i){
        cout<<num_size[i]<<endl;
    }
    return 0;
}