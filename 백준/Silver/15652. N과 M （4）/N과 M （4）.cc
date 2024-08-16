#include <vector>
#include <string>
using namespace std;
int n, m;
vector<int> N;
void DFS(string answer, int cnt, int depth){
    if(cnt == m){
        for(int i=0; i<answer.size();i++){
            printf("%c ", answer[i]);
        }
        printf("\n");
    }
    else{
        for(int j=0; j<N.size();j++){
            if(N[j]==-1) continue;
            else if(!answer.empty() && answer[answer.size()-1]-'0' > N[j]) continue;
            DFS(answer+to_string(N[j]), cnt+1, depth+1);
        }
    }
    if(depth == N.size()){
        N[answer[0]-'0'-1] = -1;
    }
}

int main(){
    scanf("%d %d", &n, &m); 
    for(int i=1; i<=n;i++){
        N.push_back(i);
    }
    DFS("", 0, 0);
    return 0;
}