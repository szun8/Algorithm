#include<iostream>
#include <string>

using namespace std;

int main(){
    string str;
    getline(cin,str);
    for(int i =0;i<str.size();++i){
        str[i]=tolower(str[i]);
    }
    if(str.find("d2")!=string::npos) cout<<"D2";
    else cout<<"unrated";

    return 0;
}