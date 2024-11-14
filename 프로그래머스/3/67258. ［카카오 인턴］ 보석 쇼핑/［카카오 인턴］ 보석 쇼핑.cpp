#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<string> gems) {
    int start = 0, end = 0;
    unordered_map<string, int> gemCnt;
    vector<int> answer = {0, 100001}; // START, END
    for (int i = 0; i < gems.size(); i++) {
        if (gemCnt.find(gems[i]) == gemCnt.end()) {
            gemCnt[gems[i]] = 0;
        }
    }   // 보석 종류 갯수 카운팅

    if (gemCnt.size() == 1) return { 1,1 };

    int typeCnt = 0;
    for (int i = 0; i < gems.size(); i++) {
        if (gemCnt[gems[i]] == 0) typeCnt++;
        gemCnt[gems[i]]++;
        if (typeCnt == gemCnt.size()) break;
        end++;
    }   // 최초 end idx 결정

    bool isOk = true;
    answer = { start, end };
    while (start <= end) {  
        if (gemCnt.size() != typeCnt) { // 모든 보석을 보유한 부분 수열이 아니라면 end를 조절하여 보유 보석 수정
            end++;
            if (end == gems.size()) break;
            else if (gemCnt.find(gems[end]) == gemCnt.end()) {
                gemCnt[gems[end]] = 1;
                if (gemCnt.size() == typeCnt) isOk = true;
            }
            else gemCnt[gems[end]]++;
        }
        else if (gemCnt[gems[start]] > 1) { // 최소 길이를 위한 중복 요소 제거
            gemCnt[gems[start]]--;
            start++;
        }
        else if (gemCnt[gems[start]] == 1) { // 전체 탐색을 위한 삭제
            gemCnt.erase(gems[start]);
            start++;
            isOk = false;
        }

        if (isOk && answer[1] - answer[0] > end - start) {  // 최종 정답은 가장 짧으면서 && 시작 번호가 작은 것으로.
            answer = { start, end };
        }
    }
    return { answer[0] + 1, answer[1] + 1 };
}