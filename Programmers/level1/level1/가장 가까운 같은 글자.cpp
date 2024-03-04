#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    map<char, int> already;

    for(int i=0;i<s.length();i++){
        map<char, int>::iterator item = already.find(s[i]);
        if(item != already.end()){    // already에 이미 있으면, value를 수정한다
            answer.push_back(i - item->second);
            item->second = i;
        }
        else{   // 없으면 새로 추가해준다.
            already.insert(pair<char, int>(s[i], i));
            answer.push_back(-1);
        }
    }
    return answer;
}

int main(){
    solution("foobar");
    return 0;
}