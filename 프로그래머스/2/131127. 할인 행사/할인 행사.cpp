#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    int buyCnt = 0;
    
    for(int i=0; i<number.size();i++){
        buyCnt += number[i];
    }
    int possibleDay = discount.size()-buyCnt+1;
    //vector<unordered_map<string, int>> days(possibleDay);
    
    for(int i=0; i<possibleDay; i++){
        unordered_map<string,int> possibleList;
        for(int j=i; j<buyCnt+i; j++){
            possibleList[discount[j]]++;
        }
        //days[i] = possibleList;
        
        bool isPossible = true;
        for(int j=0; j<want.size(); j++){
            if(possibleList[want[j]]!=number[j]){
                isPossible = false;
                break;
            }
        }
        if(isPossible) answer++;
    }
    
    for(int i=0; i<possibleDay; i++){
        
    }
    
    return answer;
}