#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    int n_one = n-1;

    // 1을 뺀 수의 약수 중 1 다음으로 큰 수가 답.
    int sqrtN_one = sqrt(n_one);

    int minAns = 1000001;
    for(int i=sqrtN_one; i>1; i--){
        if(n_one%i == 0 && minAns > i){
            minAns = i;
        }
    }

    if(minAns == 1000001) answer = n_one;
    else  answer = minAns;

    return answer;
}
