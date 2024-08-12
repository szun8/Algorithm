#include <string>
#include <vector>

using namespace std;

long long Jump(int n){
    if(n==1) return 1;
    else if(n==2) return 2;
    else if(n==3) return 3;
    
    vector<long long> answer;
    answer.push_back(1);
    answer.push_back(2);
    for(int i=1; i<n;i++){
        answer.push_back((answer[i] + answer[i-1])% 1234567);
    }
    
    return (answer[n-1]);
}

long long solution(int n) {
    return Jump(n);
}