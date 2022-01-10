#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;

int main(){
    int V,E; cin>>V>>E; // 정점, 간선의 갯수
    int dist[V+1];
    fill(dist,dist+V+1,INF);

    int K; cin>>K;  // 시작정점
    vector<pair<int,int> > graph[V+1];
    for (int i = 0; i < E; i++) {
        int u,v,w; cin>>u>>v>>w;    // from, to, val
        graph[u].push_back(pair<int,int>(v,w));
    }
    bool visited[V+1];
    fill(visited,visited+V+1,false);
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > path;   // cost, node
    dist[K]=0;
    path.push(pair<int,int>(0,K));
    while (!path.empty()) {
        int cost = path.top().first;
        int here = path.top().second;
        path.pop();

        if(!visited[here]){
            visited[here] = true;
            for (int i = 0; i < graph[here].size(); i++) {
                int next = graph[here][i].first;
                int nCost = graph[here][i].second;

                if(dist[next] > cost + nCost){
                    dist[next] = cost + nCost;
                    path.push(pair<int,int>(dist[next],next));
                }
            }
        }
    }
    
    for (int i = 1; i < V+1; i++) {
        if(dist[i]==INF) cout<<"INF\n";     // 404
        else cout<<dist[i]<<"\n";
    }
    return 0;
}