#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int input;
    cin>>input;
    int count=0;
    
    for(int i =0;i<input;++i){
        vector<char> Str;
        string str;
        cin >> str;

        for(int i =0;i<str.size();++i){
            if(i==str.size()-1&&find(Str.begin(),Str.end(),str[i])==Str.end()) {
                ++count;
            }
            else if(find(Str.begin(),Str.end(),str[i])==Str.end()){
                // 내부 벡터에 글자가 없으면 추가
                Str.push_back(str[i]);
                int num=i;
                for(int j = num+1; j<str.size();++j){ // 연속된 문자체크
                    if(str[num]==str[j]) {
                        ++i;
                        if(i==str.size()-1)
                            ++count;
                    }
                    else j=str.size();
                }
            }
            else {
                i = str.size(); // 있으면 반복문 탈출 (= 조건 불충족)
            }
        }
    }
    cout<<count;
    return 0;
}