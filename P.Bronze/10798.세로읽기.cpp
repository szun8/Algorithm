#include <iostream>
#include <vector>
using namespace std;
int main(){
    string str[5];
    int maxSize=0;
    for (int i = 0; i < 5; i++)
    {
        cin>>str[i];
        if(str[i].size()>maxSize) maxSize = str[i].size();
    }
    vector<char> line[maxSize];
    
    for (int i = 0; i < 5; i++)
    {
        int j=0;
        while(j<str[i].size()){
            line[j].push_back(str[i].at(j));
            j++;
        }
    }
    

    for (int i = 0; i < maxSize; i++)
    {
        for(int j=0;j<line[i].size();j++){
            cout<<line[i].at(j);
        }
    }
    return 0;
}