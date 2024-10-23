#include <iostream>
using namespace std;

int solution(int n)
{
    int answer = 0;
    while (n >= 1) {
        if (n % 2 == 1) {
            answer++;
            n -= 1;
        }
        n /= 2;
    }
    return answer;
}