#include <iostream>
#include <cctype>
using namespace std;

int main(){
    char str[256];
    while(true){
        cin.getline(str,256);
        if(str[0]=='#' && str[1]=='\0') return 0;
        
        int count = 0;
        for(int i = 0; str[i]!='\0';i++){
            str[i]=tolower(str[i]);
            if(str[i]=='a') ++count;
            else if(str[i]=='e') ++count;
            else if(str[i]=='i') ++count;
            else if(str[i]=='o') ++count;
            else if(str[i]=='u') ++count;
        }
        cout << count << endl;
    }
    return 0;
}