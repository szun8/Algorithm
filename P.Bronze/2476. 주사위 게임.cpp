#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N,cost; cin>>N;
    vector<int> person(N);
    for (int i = 0; i < N; i++) {
        int num[3]; cin>>num[0]>>num[1]>>num[2];
        sort(num,num+3);
        int a=num[0], b=num[1], c=num[2];
        if(a==b && b==c){
            cost = 10000+(a*1000);
        }
        else if(a==b){
            cost = 1000+(a*100);
        }
        else if(b==c){
            cost = 1000+(b*100);
        }
        else if(a==c){
            cost = 1000+(c*100);
        }
        else {
            cost = c*100;
        }
        person[i] = cost;
    }
    cout<<*max_element(person.begin(),person.end());
    return 0;
}