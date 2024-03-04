#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    string todayYear = today.substr(0,4);
    int ty = stoi(todayYear);
    string todayMonth = today.substr(5,2);
    int tm = stoi(todayMonth);
    string todayDay = today.substr(8,2);
    int td = stoi(todayDay);
    int totalToday = td + (tm * 28) + (ty * 28 * 12); // 총 오늘까지의 일수

    map<char, int> termNum;
    for(int i=0; i<terms.size(); i++){
        termNum[terms[i][0]] = stoi(terms[i].substr(2));
    }
    
    for(int i=0; i<privacies.size();i++){
        int okMonth = termNum[privacies[i][11]]; // 알파벳에 따른 보관기간 저장
        int okDay = okMonth * 28;

        // 개인정보에 대한 수집일 파싱
        string year = privacies[i].substr(0,4);
        int y = stoi(year);
        string month = privacies[i].substr(5,2);
        int m = stoi(month);
        string day = privacies[i].substr(8,2);
        int d = stoi(day);
        
        int total = d + (m*28) + (y*12*28) + okDay - 1;
        
        // 이제 오늘을 기준으로 계산된 날짜가 이전이면 answer에 포함시킴
        if(total < totalToday) answer.push_back(i+1);
    }
    return answer;
}

int main(){
    string today="2020.01.01";
    vector<string> terms(2);
    terms[0] = "Z 3";
    terms[1] = "D 5";
    vector<string> privacies(5);
    privacies[0]="2019.01.01 D";
    privacies[1]="2019.11.15 Z";
    privacies[2]="2019.08.02 D";
    privacies[3]="2019.07.01 D";
    privacies[4]="2018.12.28 Z";

    solution(today, terms, privacies);
    return 0;
}