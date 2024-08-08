#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;
vector<int> solution(vector<string> operations) {
    vector<int> answer;
    deque<int> dq;
    
    for(int i=0; i<operations.size();i++){
        if(operations[i][0] == 'I'){    // insert
            int input = stoi(operations[i].substr(2));
            dq.push_back(input);
        }
        else if(operations[i][0] == 'D'){ 
            if(dq.empty()) continue;
            else if(dq.size() > 1) sort(dq.begin(), dq.end());

            if(operations[i][2] == '1'){    // max
                dq.pop_back();
            }else{  // min
                dq.pop_front();
            }
        }
    }
    if(dq.empty()){
        answer.push_back(0);
        answer.push_back(0);
    }
    else{
        if(dq.size() > 1) sort(dq.begin(), dq.end());
        answer.push_back(dq.back());
        answer.push_back(dq.front()); 
    }

    return answer;
}