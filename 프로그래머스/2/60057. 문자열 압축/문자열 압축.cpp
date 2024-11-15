#include <iostream>
#include <string>
using namespace std;

int solution(string s) {
    int strSize = s.length();
    int answer = strSize;
    int cnt = 0;
    for (int i = 1; i <= strSize; i++) {
        cnt = 0;
        string result = "";
        string beforeStr = "";
        string restStr = "";
        for (int j = 0; j < strSize; j += i) {
            if (strSize - j >= i) { // i크기 만큼 자를 수 있는 경우
                string tmp = s.substr(j, i);
                if (beforeStr == "") {
                    cnt = 1; // reset
                }
                else if (beforeStr != tmp) {
                    if (cnt == 1) result += beforeStr;
                    else result += (to_string(cnt) + beforeStr);
                    cnt = 1; // reset
                }
                else cnt++;
                beforeStr = tmp;
            }
            else restStr = s.substr(j);
        }

        if (cnt == 1) result += beforeStr;
        else result += (to_string(cnt) + beforeStr);

        result += restStr; // 나머지 문자열이 있다면 합쳐주기
        if (answer > result.length()) answer = result.length(); // 결과 갱신
    }
    return answer;
}