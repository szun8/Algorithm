#include <string>
#include <vector>
#include <queue>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    queue<string> c1, c2;

    for (int i = 0; i < cards1.size(); i++)
    {
        c1.push(cards1[i]);
    }
    for (int i = 0; i < cards2.size(); i++)
    {
        c2.push(cards2[i]);
    }
    
    for(int i=0; i<goal.size();i++){
        if(c1.front() == goal[i]) c1.pop();
        else if(c2.front()==goal[i]) c2.pop();
        else {
            return "No";
        }
    }
    return "Yes";
}

int main(){
    vector<string> cards1;
    cards1 = { "i", "drink", "water"};
    vector<string> cards2;
    cards2 = { "want", "to"};
    vector<string> goal;
    goal = {"i", "want", "to", "drink", "water"};
    
    solution(cards1, cards2,goal);

    return 0;
}