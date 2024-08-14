#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    map<char, int> keyboard;
    
    for(int i=0; i<keymap.size();i++){
        for(int j=0; j<keymap[i].size();j++){
            if(keyboard[keymap[i][j]] == 0) keyboard[keymap[i][j]] = j+1;
            else if(keyboard[keymap[i][j]] > j+1){
                keyboard[keymap[i][j]] = j+1;
            }
        }
    }
    
    for(int i=0; i<targets.size(); i++){
        int cnt = 0;
        for(int j=0; j<targets[i].size(); j++){
            if(keyboard[targets[i][j]]==0){
                cnt = -1;
                break;
            }
            else cnt += keyboard[targets[i][j]];
        }
        answer.push_back(cnt);
    }
    return answer;
}