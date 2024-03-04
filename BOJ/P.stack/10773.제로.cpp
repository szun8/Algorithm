#include <iostream>
#include <stack>
using namespace std;

int main(){
    int k;
    cin>>k;
    int sum=0;
    stack<int> sums;
    for (int i = 0; i < k; i++)
    {
        int num;
        cin>>num;
        if(num==0) sums.pop();
        else sums.push(num);
    }

    while(!sums.empty()){
        sum+=sums.top();
        sums.pop();
    }
    cout<<sum;
    return 0;
}