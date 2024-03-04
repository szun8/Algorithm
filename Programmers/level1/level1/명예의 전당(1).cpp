#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    multiset<int, greater<int>> ranking;    // 내림차순 정렬을 위해 greater지정

    for (int i = 0; i < score.size(); i++)
    {
        if(ranking.size() == k && *(--ranking.end()) < score[i]){
            // set.end()는 가장 마지막 원소의 바로 다음 iterator를 반환한다.
            ranking.erase((--ranking.end()));
            ranking.insert(score[i]);
        }
        else if(ranking.size() < k){
            ranking.insert(score[i]);
        }
        answer.push_back(*(--ranking.end()));
    }
    return answer;
}

int main(){
    vector<int> score;
    score = {10, 100, 20, 150, 1, 100, 200};
    solution(3, score);
    return 0;
}