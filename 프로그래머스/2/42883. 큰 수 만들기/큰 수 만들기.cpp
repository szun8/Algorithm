#include <string>
#include <vector>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    int answerSize = number.size() - k; 
    int firstIdx = -1;
    char firstMax = '0';
    int a = 0;
    int cnt = 0;

    while (answer.size() != answerSize) {
        firstMax = '0';
        for (int i = number.size() - answerSize + a; i >= 0; i--) {
            if (number[i] >= firstMax) {
                firstMax = number[i];
                firstIdx = i;
            }
        }
        answer += number[firstIdx]; // 7
        number = number.substr(firstIdx+1, number.size()); //7252841
        cnt += firstIdx;    // cnt = 3
        a++;    // 1
    }
    return answer;  // 9841
}