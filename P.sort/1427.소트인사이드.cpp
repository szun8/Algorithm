#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;

    string sortN = to_string(n);
    sort(sortN.begin(),sortN.end(),greater<char>());
    cout<<sortN;
    return 0;
}