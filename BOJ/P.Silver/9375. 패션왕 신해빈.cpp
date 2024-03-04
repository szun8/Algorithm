#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main(){
    int testCase; cin>>testCase;
    
    for (int i = 0; i < testCase; i++)
    {
        int clothesNum; cin>>clothesNum;
        unordered_map<string, int> clothes; //의상의 종류, 의상의 갯수
        for(int j=0; j<clothesNum; j++){
            string name, type;
            cin>>name>>type;
            if(clothes[type]>1){
                clothes[type]++;    // 종류 증가
            }
            else{
                clothes[type] = 2;  // 안입은 경우의수까지 더해서 초기화 시켜주기
            }
        }
        int cnt = 1;
        for(unordered_map<string, int>::iterator iter = clothes.begin(); iter!=clothes.end(); iter++){
            cnt*=iter->second;  // 전체 경우의수
        }
        printf("%d\n", cnt-1);  // 전체 다 안입은 경우의수 1을 뺴고 출력
    }
    return 0;
}