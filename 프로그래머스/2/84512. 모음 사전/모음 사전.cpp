#include <string>
#include <vector>

using namespace std;

int solution(string word) {
    int answer = 0;
    
    string vowels[5] = {"A","E","I","O","U"};
    int cntChildren[5] = {781, 156, 31, 6, 1};
    
    for(int i=0; i<word.size(); i++){
        int idx = -1;
        if(word[i]=='A') idx= 0;
        else if(word[i]=='E') idx= 1;
        else if(word[i]=='I') idx= 2;
        else if(word[i]=='O') idx= 3;
        else if(word[i]=='U') idx= 4;
        
        answer += cntChildren[i]*idx+1;
    }

    return answer;
}