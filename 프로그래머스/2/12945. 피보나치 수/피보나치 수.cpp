#include <string>
#include <vector>

using namespace std;

long long Fibo(int n){
    if(n==2) return 1;
    
    vector<long long> answer;
    answer.push_back(0);
    answer.push_back(1);
    for(int i=1; i<n;i++){
        answer.push_back((answer[i] + answer[i-1])% 1234567);
    }
    
    return (answer[n]);
}

long long solution(int n) {
    return Fibo(n);
}