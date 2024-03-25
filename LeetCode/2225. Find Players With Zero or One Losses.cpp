#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<vector<int>> findWinners(vector<vector<int>>& matches) {
    unordered_map<int, pair<int,int>> players;
    vector<vector<int>> answer(2);

    for (int i = 0; i < matches.size(); i++) {
        players[matches[i][0]].first++;
        players[matches[i][1]].second++;
    }

    for (auto iter = players.begin(); iter != players.end(); iter++) {
        if(iter->second.first > 0 && iter->second.second == 0) answer[0].push_back(iter->first);
        else if(iter->second.second == 1)  answer[1].push_back(iter->first);
    }

    sort(answer[0].begin(), answer[0].end());
    sort(answer[1].begin(), answer[1].end());
    return answer;
}

int main() {
    vector<vector<int> > matches = { {1,3}, {2,3}, {3,6}, {5,6}, {5,7}, {4,5}, {4,8}, {4,9}, {10, 4}, {10,9} };
    vector<vector<int> > ans = findWinners(matches);
}