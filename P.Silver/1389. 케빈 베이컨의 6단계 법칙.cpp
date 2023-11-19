#include <iostream>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <vector>
using namespace std;

bool isDone;
vector<vector<int> > relations;
void Find(int startNode, int endNode, vector<int>* graph, int s, int e, int cnt, vector<bool> visited){
    if(startNode == endNode && relations[s][e]>cnt) {
        relations[s][e] = cnt;
        relations[e][s] = cnt;
        return;
    }

    ++cnt;
    visited[startNode] = true;  // 해당 노드 방문 완료
    
    for(long unsigned int i=0; i<graph[startNode].size(); i++){
        if(!visited[graph[startNode][i]]) Find(graph[startNode][i], endNode, graph, s, e, cnt, visited);
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n,m; cin>>n>>m;
    vector<int> graphs[n+1];
    vector<bool> visited;
    visited.resize(n+1, false);
    relations.resize(n+1, vector<int>(n+1, 99999));

    for(int i=0; i<m; i++){
        int x,y; cin>>x>>y;
        graphs[x].push_back(y);
        graphs[y].push_back(x);
        relations[x][y] = 1;
        relations[y][x] = 1;
    }
    for(int i=1; i<n+1;i++){
        sort(graphs[i].begin(), graphs[i].end());
    }

    for(int i=1; i<n+1; i++){
        for(int j=1; j<n+1; j++){
            if(i==j) continue;  // 같은 노드는 0
            else if(relations[i][j]==1 || relations[i][j]!=99999) continue;   // 직접 연결되었다면 탐색 불필요

            visited.assign(n+1, false);
            isDone=false;
            Find(i,j, graphs,i,j, 0, visited);
        }
    }
    typedef pair<int, int> sums;
    sums min = make_pair(0, INFINITY);
    for(int i=1; i<n+1; i++){
        int tmp = 0;
        for(int j=1; j<n+1; j++){
            if(relations[i][j]!=99999) tmp+=relations[i][j];
        }
        if(min.second>tmp){
            min.first=i;
            min.second=tmp;
        }
    }

    printf("%d", min.first);
    return 0;
}