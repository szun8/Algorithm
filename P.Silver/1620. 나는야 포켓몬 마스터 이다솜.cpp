#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

vector<string> poketmon;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n; // 포켓몬의 개수
    int m; // 내가 맞춰야 하는 문제의 개수
    cin>>n>>m;
    map<string, int> hashPoketmon;

    poketmon.resize(n);
    for(int i=0; i<n; i++){
        string name;
        cin>>name;
        poketmon[i] = name;                         // 번호로 찾을 수 있게 vector
        hashPoketmon.insert(make_pair(name, i+1));    // 이름으로 찾을 수 있게 map
    }

    vector<string> result;
    for(int i=0; i<m; i++){
        string what;
        cin>>what;
        if(what[0]>48 && what[0]<58){ // 입력이 숫자인 경우, 문자를 배출한다
            int num = stoi(what);
            result.push_back(poketmon[num-1]);
        }
        else{ // 입력이 문자인 경우, 숫자를 배출한다
            result.push_back(to_string(hashPoketmon[what]));
        }
    }

    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<"\n"; // endl은 정말 시간^^초과의 주범 ^^~
    }
    return 0;
}