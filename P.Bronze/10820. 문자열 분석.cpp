#include <iostream>
#include <string>
using namespace std;
int main(){
    string str;
    int count=0;
    while (count<100 && getline(cin,str))
    {
        int big=0, small=0, number=0,space=0;
        for (int i = 0; i < str.size(); i++)
        {
            if(str[i]==' ') ++space;
            else if(str[i]<=57 && str[i]>= 48) ++number;
            else if(str[i] >= 65 && str[i] <= 95) ++big;
            else if(str[i] >=  97 && str[i] <= 122) ++small;
        }
        cout<<small<<" "<<big<<" "<<number<<" "<<space<<"\n";
        ++count;
    }
    
    return 0;
}