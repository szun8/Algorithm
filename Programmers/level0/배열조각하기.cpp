#include <string>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr, vector<int> query) {
    vector<int> answer;
    
    for (int i = 0; i < query.size(); i++)
    {
        if(i%2==0){ // 짝수면 뒤를 버림
            int size = arr.size()-1;
            for(int j=query[i];j<size;j++){
                arr.pop_back();
            }
        }
        else{       // 홀수면 앞을 버림
            for(int j=query[i]; j>0;j--){
                arr.erase(arr.begin());
            }
        }
    }
    
    return answer = arr;
}

int main(){
    vector<int> arr;
    arr = {0, 1, 2, 3, 4, 5};
    vector<int> query;
    query = {4,1,2};
    solution(arr, query);
    return 0;
}