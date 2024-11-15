#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(string s) {
    unordered_map<string, int> compression;
    int strSize = s.length();
    int answer = strSize;

    for (int i = 1; i <= strSize; i++) {
        compression.clear();
        string result = "";
        string beforeStr = "";
        string restStr = "";
        for (int j = 0; j < strSize; j += i) {
            if (strSize - j >= i) { // i크기 만큼 자를 수 있는 경우
                string tmp = s.substr(j, i);
                if (compression.find(tmp) == compression.end()) {
                    compression[tmp] = 1;
                }
                else {
                    if (tmp != beforeStr) {
                        // 이미 있는데 이전 문자열과 다르다면, 중복이지만 연속적인 문자가 아님 -> 여태까지 결과 축적해서 클리어 시키기
                        for (auto it = compression.begin(); it != compression.end(); it++) {
                            if (it->second == 1) result += it->first;
                            else result += (to_string(it->second) + it->first);
                        } compression.clear();
                        compression[tmp] = 1;
                    }
                    else compression[tmp]++;
                }
                beforeStr = tmp;
            }
            else restStr = s.substr(j);
        }
        for (auto it = compression.begin(); it != compression.end(); it++) {
            if (it->second == 1) result += it->first;
            else result += (to_string(it->second) + it->first);
        } result += restStr;
        if (answer > result.length()) answer = result.length();
    }
    return answer;
}

int main() {
    solution("abcde");
    return 0;
}