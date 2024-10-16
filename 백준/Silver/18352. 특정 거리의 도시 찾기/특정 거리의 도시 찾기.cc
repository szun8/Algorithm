#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

const int INF = numeric_limits<int>::max();
int n, m, k, x;

void Dijkstra(vector<vector<int> >& graph, int start, vector<int>& dist){
    queue<int> q;
    dist[start] = 0;
    q.push(start);

    while(!q.empty()){
        int curNode = q.front(); q.pop();
        
        for(int node : graph[curNode]){
            if(dist[node] == INF){
                dist[node] = dist[curNode]+1;
                q.push(node);
            }
        }
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n>>m>>k>>x;

    vector<vector<int> > graph(n+1);
    vector<int> dist(n+1, INF);
    
    for(int i=0; i<m;i++){
        int a, b;
        cin>>a>>b;
        graph[a].push_back(b);
    }

    Dijkstra(graph, x, dist);

    if(none_of(dist.begin(), dist.end(), [](int i) { return i == k; }))
        printf("-1");
    else{
        for(int i = 1; i<n+1; i++){
            if(dist[i] == k) printf("%d\n", i);
        }
    }
    return 0;
}