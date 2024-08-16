#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    unordered_map<string, int> playerIdx;
    for(int i=0; i<players.size();i++){
        playerIdx[players[i]] = i;
    }
    
    for(int i=0; i<callings.size();i++){
        int curIdx = playerIdx[callings[i]];
        int newIdx = curIdx -1;
        
        string tmpName = players[newIdx];
        players[newIdx] = players[curIdx];
        players[curIdx] = tmpName;
        
        playerIdx[callings[i]]--;
        playerIdx[tmpName]++;
    }
    return players;
}