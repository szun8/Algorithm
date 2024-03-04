#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    map<char, int> keyboard;            // 작성할수 있는 문자와 그 문자를 치기까지 터치하는 최소 횟수를 저장하는 map
    for(int i=0; i<keymap.size();i++){  // 작성할 수 있는 문자와 횟수를 초기화하는 반복문
        for(int j=0; j<keymap[i].length();j++){
            map<char, int>::iterator iter = keyboard.find(keymap[i][j]);
            if(iter!= keyboard.end() && keyboard[keymap[i][j]] > j+1) {  // 이미 존재 && 지금나온 횟수가 더 적으면 갱신
                 keyboard[keymap[i][j]] = j+1;
            }
            else {   // 이미 존재하지 않으면 새로이 추가 (중복무시)
                keyboard.insert(pair<char, int>(keymap[i][j], j+1));
            }
        }
    }
    for(int i=0; i<targets.size();i++){ // 타겟 문자의 터치 횟수를 구하는 반복문
        int cnt = 0;
        for(int j=0; j<targets[i].length();j++){
            if(keyboard.find(targets[i][j]) != keyboard.end())  // 원하는 문자작성이 가능하면 횟수에 포함
                cnt+=keyboard[targets[i][j]];
            else {  // 그렇지 못하면 -1을 저장하고 해당 타켓의 반복을 종료
                cnt = -1;
                break;
            }
        }
        answer.push_back(cnt);
    }
    return answer;
}

int main(){
    vector<string> keymap;
    keymap = {"AA"};

    vector<string> targets;
    targets = {"B"};

    solution(keymap, targets);
    return 0;
}