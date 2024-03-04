#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> delete_list) {
    vector<int> answer;
    for (int i = 0; i < arr.size(); i++)
    {
       if(find(delete_list.begin(), delete_list.end(), arr[i])==delete_list.end()){
        answer.push_back(arr[i]);
       }
    }
    return answer;
}

int main(){
    vector<int> arr;
    arr.push_back(293);
    arr.push_back(1000);
    arr.push_back(395);
    arr.push_back(678);
    arr.push_back(94);

    vector<int> delete_list;
    delete_list.push_back(94);
    delete_list.push_back(777);
    delete_list.push_back(104);
    delete_list.push_back(1000);
    delete_list.push_back(1);
    delete_list.push_back(12);
    vector<int> res = solution(arr, delete_list);
    for (int i = 0; i < res.size(); i++)
    {
        cout<<res[i]<<endl;
    }
    return 0;
}