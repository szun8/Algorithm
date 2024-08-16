#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
int n, m;
void DFS(map<int, int> N, vector<int> answer, int cnt){
    if(cnt == m){
        for(int i=0; i<answer.size();i++){
            printf("%d ", answer[i]);
        }
        printf("\n");
    }
    else{
        for(map<int, int>::iterator iter = N.begin(); iter != N.end(); iter++){    // 중복 허용
            if(iter->second == 0) continue;
            map<int, int> tmp = N;
            vector<int> tmpAnswer = answer;
            
            tmp[iter->first]--;
            tmpAnswer.push_back(iter->first);
            DFS(tmp, tmpAnswer, cnt+1);
        }
    }
}

int main(){
    scanf("%d %d", &n, &m); 
    map<int, int> N;

    for(int i=1; i<=n;i++){
        int input;
        scanf("%d", &input);
        N[input]++;
    }
    vector<int> blank;
    DFS(N, blank, 0);
    return 0;
}