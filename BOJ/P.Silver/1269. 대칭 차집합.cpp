#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main(){
    int numA, numB; cin>>numA>>numB;
    unordered_map<int, int> sets;

    vector<int> setA, setB;
    for(int i=0; i<numA;i++){
        int num; cin>>num;
        sets[num] = 1;
    }

    for(int i=0; i<numB;i++){
        int num; cin>>num;
        if(sets[num]==1){   // A집합과 교집합인 원소는 2로 바꾼다.
            sets[num]=2;
        }
        else{
            sets[num]=1;    // A집합과 교집합이지 않은 원소는 1로 저장한다.
        }
    }
    int cnt=0;  // 대칭 차집합의 갯수 = map의 value가 1인 것
    for(unordered_map<int, int>::iterator iter=sets.begin(); iter!=sets.end(); iter++){
        if(iter->second==1) ++cnt;
    }
    printf("%d", cnt);
    return 0;
}