#include <vector>
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    struct Temp{
        int temp, index;
    }current;

    vector<int> dailyTemperatures(vector<int>& temperatures) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
         
        stack<Temp> day;
        vector<int> answer(temperatures.size(),0);

        for(int i=0; i<temperatures.size(); i++){
            while(!day.empty() && day.top().temp < temperatures[i]){
                int temp = day.top().temp;
                int index = day.top().index;
                answer[index] = i-index;
                day.pop();
            }
            current.temp = temperatures[i];
            current.index = i;
            day.push(current);
        }
        return answer;
    }
};