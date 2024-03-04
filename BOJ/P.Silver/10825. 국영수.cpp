#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class score {
public:
    string name;
    int korean;
    int english;
    int math;

public:
    score(string n, int k, int e, int m){
        name=n;
        korean=k;
        english=e;
        math=m;
    }
};

bool cmp(score a, score b){
    if(a.korean != b.korean) return a.korean > b.korean;    //국어점수가 감소하는 순 = 내림차순
    else if(a.english != b.english) return a.english < b.english; //영어점수가 증가하는 순 = 오름차순
    else if(a.math != b.math) return a.math > b.math;   //수학점수가 감소하는 순 = 내림차순
    else return a.name < b.name;  //사전순
}   

int main(){
    int n;
    cin>>n;
    vector<score> student;
    for (int i = 0; i < n; i++)
    {
        string name;
        cin>>name;
        int K, E, M;
        cin>>K>>E>>M;
        score person(name,K,E,M);

        student.push_back(person);
    }
    stable_sort(student.begin(),student.end(),cmp);

    for (int i = 0; i < n; i++)
    {
        cout<<student[i].name<<"\n";
    }
    
    return 0;
}