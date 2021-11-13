#include <iostream>
using namespace std;

int main(){
    string id;
    cin>>id;
    id.push_back('?');
    id.push_back('?');
    id.push_back('!');

    cout<<id;
    return 0;
}