#include <iostream>
#include <vector>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    vector<int> line;
    int rule[100001];
    vector<char> out;

    int count=0;    // stack에 들어가는 수 count
    int ruleCount=0;    // 임의 수열이 체크됐는지 아닌지 확인

    int n;
    scanf("%d",&n);

    for(int i=0; i<n;++i) scanf("%d",&rule[i]);

    for (int i = 1; i <= n; i++)
    {
        line.push_back(i);
        out.push_back('+');
        while (!line.empty() && line.back() == rule[ruleCount]) {
            line.pop_back();
            out.push_back('-'); 
            ruleCount++;
        }
    }
    

    if(!line.empty()) printf("NO");
    else{
        for(int i = 0;i<out.size();++i){
            cout<<out[i]<<"\n";
        }
    }
    return 0;
}