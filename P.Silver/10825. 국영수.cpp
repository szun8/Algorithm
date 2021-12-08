#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class score {
public:
    int korean;
    int english;
    int math;

public:
    score(int k, int e, int m){
        korean=k;
        english=e;
        math=m;
    }
};

bool cmp(pair<string,score> a, pair<string,score> b){
    if(a.second.korean != b.second.korean) return a.second.korean > b.second.korean;    //국어점수가 감소하는 순 = 내림차순
    else if(a.second.english != b.second.english) return a.second.english < b.second.english; //영어점수가 증가하는 순 = 오름차순
    else if(a.second.math != b.second.math) return a.second.math > b.second.math;   //수학점수가 감소하는 순 = 내림차순
    else return a.first < b.first;  //사전순
}   

int main(){
    int n;
    cin>>n;
    vector<pair<string,score> > student;
    for (int i = 0; i < n; i++)
    {
        string name;
        cin>>name;
        int K, E, M;
        cin>>K>>E>>M;
        score person(K,E,M);

        student.push_back(pair<string,score>(name, person));
    }
    stable_sort(student.begin(),student.end(),cmp);

    for (int i = 0; i < n; i++)
    {
        cout<<student[i].first<<"\n";
    }
    
    return 0;
}