#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n,j;
    cin>>n>>j;
    vector<string> memory(n);

    for (int i = 0; i < n; i++)
    {
        cin>>memory[i];
    }
    sort(memory.begin(),memory.end());
    cout<<memory[j-1];
    return 0;
}