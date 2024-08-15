#include <unordered_map>
#include <vector>
#include <string>
using namespace std;
class aaa {
public:
    unordered_map<string, double> answer;
};

class Solution {
public:
    unordered_map<string, aaa> johab; // = unordered_map<string, unordered_map<string, double>>
    unordered_map<string, bool> visited;
    unordered_map<string, bool> visitedOrigin;
    double answerNum = -1;
public:
    vector<double> calcEquation(
        vector<vector<string>>& equations,
        vector<double>& values,
        vector<vector<string>>& queries)
    {
        vector<double> answer;
        for (int i = 0; i < equations.size(); i++) {
            aaa& tmp = johab[equations[i][0]];
            tmp.answer[equations[i][1]] = values[i];
            tmp.answer[equations[i][0]] = 1;

            aaa& tmp1 = johab[equations[i][1]];
            tmp1.answer[equations[i][0]] = 1 / values[i];
            tmp1.answer[equations[i][1]] = 1;

            visited[equations[i][0]] = false;
            visited[equations[i][1]] = false;
        }
        visitedOrigin = visited;
      
        for (int i = 0; i < queries.size(); i++) {
            answerNum = -1;
            visited = visitedOrigin;  // 방문 기록 초기화
            DFS(queries[i][0], queries[i][1],1);
            answer.push_back(answerNum);
        }
        return answer;
    }

    // visited check
    void DFS(string src, string& target, double num) {
        if (answerNum != -1) return;

        aaa& tmp = johab[src];
        visited[src] = true;
        for (auto i = tmp.answer.begin(); i != tmp.answer.end(); i++) {
            if (answerNum != -1) return;
            else if (i->first == target) {
                answerNum = i->second * num;
                return;
            }
            else if (!visited[i->first]) DFS(i->first, target, i->second * num);
        }
    }
};
