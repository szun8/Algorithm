#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    cin.ignore();
    string str;
    
    vector<char> Str;
    for (int i = 0; i < n; i++) {
        getline(cin, str);
        for(int j=0;j<str.size();j++){
            if(str[j]!=' ') {
                vector<char> reverseStr;
                int a=j;
                while(true){
                    reverseStr.push_back(str[j]);
                    if(str[j+1]!=' ' && str[j+1]!='\0') j++;
                    else break;
                }
                reverse(reverseStr.begin(),reverseStr.end());   //바꿔주기
                int b=0;
                while(true){
                    str[a]=reverseStr[b];
                    if(str[a+1]!=' ' && str[a+1]!='\0'){
                         a++;
                         b++;
                    }
                    else break;
                }
            }
        }
        cout<<str<<endl;
    }
    return 0;
}