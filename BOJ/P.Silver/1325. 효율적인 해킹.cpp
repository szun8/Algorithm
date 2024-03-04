#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int> > computers;
vector<bool> visited;
vector<int> relations;  // 누적합

void BFS(int node){
    queue<int> nodeQ;
    nodeQ.push(node);
    visited[node] = true;

    while (!nodeQ.empty())
    {
        int cur = nodeQ.front();
        nodeQ.pop();

        for(int i=0; i<computers[cur].size(); i++){
            if(!visited[computers[cur][i]]){
                visited[computers[cur][i]] = true;
                relations[computers[cur][i]]++;

                nodeQ.push(computers[cur][i]);
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m; cin>>n>>m;
    computers.resize(n+1);
    visited.resize(n+1, false);
    relations.resize(n+1, 0);

    for(int i=0; i<m; i++){
        int s, e;
        cin>>s>>e;
        computers[s].push_back(e);
    }

    for(int i=1; i<n+1; i++){
        if(computers[i].empty()) continue;
        visited.assign(n+1, false);
        BFS(i);
    }

    int max = *max_element(relations.begin(), relations.end());
    for(int i=1; i<n+1; i++){
        if(relations[i]==max){
            printf("%d ", i);
        }
    }
    return 0;
}