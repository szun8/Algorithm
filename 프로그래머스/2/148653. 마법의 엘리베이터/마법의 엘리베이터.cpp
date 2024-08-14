#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
    int answer = 0;
    int a = 1;
    
    while(storey > 0){
        int b = storey % 10;
        if(b==5){
            if(storey == b){
                answer+=5;
                break;
            }
            else if(storey > 10 && (storey % 100) / 10 >= 5){
                answer += 5;
                storey -= b;
                storey += 10;
            }
            else answer += b;
        }
        else if(b > 5){    // 6~9
            answer += (10-b);   // 더해준 것이므로 앞의 자릿수를 늘려줘야함
            storey -= b;
            storey += 10;
        }
        else { // 4~1
            answer += b;
        }
        storey /= 10;
    }
    return answer;
}