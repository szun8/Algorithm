#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
int incomingEdge[32001];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n,m;
    cin>>n>>m;
    vector<int> graph[n+1];
    queue<int> sorting;
    memset(incomingEdge,0,sizeof(incomingEdge));
    for (int i = 0; i < m; i++) {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);  // b 앞에 a가 들어온다 , a의 진출노드 b 삽입(a->b)
        ++incomingEdge[b];      // a 에 따른 b 진입차수 1 증가
    }
    for (int i = 1; i < n+1; i++) {
        if(incomingEdge[i]==0) {
            sorting.push(i);    // 진입차수가 0인 정점들을 정렬큐에 삽입
            incomingEdge[i]=-1;
        }
    }
    while (!sorting.empty()) {
        int node = sorting.front();
        sorting.pop();
        cout<<node<<" ";
        for (int i = 0; i < graph[node].size(); i++) {
            int nextNode = graph[node][i];
            incomingEdge[nextNode]--;   // 현 node를 정렬해줌으로써, node랑 연결된 nextnode의 진입차수 1감소
        }
        for (int i = 1; i < n+1; i++) { // 다음 정렬될 진입차수가 0인 미방문 node 탐색
            if(incomingEdge[i]==0) {
                sorting.push(i);
                incomingEdge[i]=-1;
            }
        }
    }
    return 0;
}