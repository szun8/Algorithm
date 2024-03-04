#include <iostream>
#include <vector>
using namespace std;

int main(){
    int input;
    cin >> input;

    int x;
    cin >> x;

    vector<int> A;
    for(int i =0;i<input;++i){
        int a;
        cin >> a;
        A.push_back(a);
    }

    for(int i =0;i<A.size();++i){
        if(A[i]<x)  cout<<A[i]<<" ";
    }
    return 0;
}