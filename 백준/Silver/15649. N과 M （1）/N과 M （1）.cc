#include <vector>
#include <string>
using namespace std;
int n, m;
void DFS(vector<int> curN, string answer, int cnt){
    if(cnt == m){
        for(int i=0; i<answer.size();i++){
            printf("%c ", answer[i]);
        }
        printf("\n");
    }
    else{
        for(int j=0; j<curN.size();j++){
            if(curN[j]==-1) continue;
            int addNum = curN[j];
            vector<int> tmp = curN;
            tmp[j] = -1;
            DFS(tmp, answer+to_string(addNum), cnt+1);
        }
    }
}

int main(){
    scanf("%d %d", &n, &m);
    vector<int> N;
    for(int i=1; i<=n;i++){
        N.push_back(i);
    }
    DFS(N, "", 0);
    return 0;
}