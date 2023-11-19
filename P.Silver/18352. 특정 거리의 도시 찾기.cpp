#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

static vector<vector<int> > map;
static vector<int> visited;
static vector<int> result;

void BFS(int node){
    queue<int> nodeQ;
    nodeQ.push(node);
    visited[node]++;

    while(!nodeQ.empty()){
        int cur = nodeQ.front();
        nodeQ.pop();
        for(unsigned int i = 0 ; i<map[cur].size(); i++){
            if(visited[map[cur][i]]==-1){
                visited[map[cur][i]] = visited[cur]+1;
                nodeQ.push(map[cur][i]); // 얘를 조건문안에 같이 안넣어줘서 스택 오버플로우 (메모리초과)남;;
            }  
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m, k, x;

    cin>>n>>m>>k>>x;
    map.resize(n+1);
    visited.resize(n+1, -1);

    for(int i=0; i<m; i++){
        int s, e;
        cin>>s>>e;
        map[s].push_back(e);
    }
    BFS(x);

    
    for(unsigned int i=1; i<visited.size(); i++){
        if(visited[i]==k){
            result.push_back(i);
        }
    }
    if(result.size()==0) {
        printf("-1");
        return 0;
    }

    sort(result.begin(), result.end());
    
    for(unsigned int i=0; i<result.size(); i++){
        printf("%d\n", result[i]);
    }
    return 0;
}