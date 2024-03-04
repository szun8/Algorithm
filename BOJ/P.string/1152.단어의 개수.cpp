#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(char a){
    return a==' ';
    // 공백(space)라면 +1
}
int main(){
    
    string str;
    getline(cin,str);
    
    int count=count_if(str.begin(),str.end(),cmp);

    if(str[0]==' ') --count;
    if(str.back()==' ') --count;
    cout<<count+1;
    return 0;
}