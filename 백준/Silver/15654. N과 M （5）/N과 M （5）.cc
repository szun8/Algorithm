#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int n, m;
void DFS(vector<int> N, vector<int> answer, int cnt){
    if(cnt == m){
        for(int i=0; i<answer.size();i++){
            printf("%d ", answer[i]);
        }
        printf("\n");
    }
    else{
        for(int j=0; j<N.size();j++){
            if(N[j] == -1) continue;
            vector<int> tmp = N;
            vector<int> tmpAnswer = answer;
            tmp[j] = -1;
            tmpAnswer.push_back(N[j]);
            DFS(tmp,tmpAnswer, cnt+1);
        }
    }
}

int main(){
    scanf("%d %d", &n, &m); 
    vector<int> N;

    for(int i=1; i<=n;i++){
        int input;
        scanf("%d", &input);
        N.push_back(input);
    }
    sort(N.begin(), N.end());
    vector<int> blank;
    DFS(N, blank, 0);
    return 0;
}