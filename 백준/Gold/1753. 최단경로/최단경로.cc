#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

#define INF numeric_limits<int>::max()

//const int INF = numeric_limits<int>::max();
int v, e, k;

void Dijkstra(vector<vector<pair<int, int> > > & graph, int start, vector<int>& dist){
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq; // weight, node
    dist[start] = 0;
    pq.push({0, start});

    int curNode, nextNode, nextWeight;
    while(!pq.empty()){
        curNode = pq.top().second;
        pq.pop();
        
        for(pair<int,int> node : graph[curNode]){
            nextNode = node.first;
            nextWeight = node.second;

            if(dist[nextNode] > dist[curNode] + nextWeight){
                dist[nextNode] = dist[curNode] + nextWeight;
                pq.push({dist[nextNode], nextNode});
            }
        }
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>v>>e;
    cin>>k;

    vector<vector<pair<int, int> > > graph(v+1);
    vector<int> dist(v+1, INF);
    
    int from, to, weight;
    for(int i=0; i<e;i++){
        cin>>from>>to>>weight;
        auto iter = find_if(graph[from].begin(), graph[from].end(), [to](pair<int,int> i){ return i.first == to; });
        if(iter != graph[from].end()){
            if(iter->second > weight){
                iter->second = weight;
            } 
        }else{
            graph[from].push_back({to, weight});
        }
    }

    Dijkstra(graph, k, dist);

    for(int i = 1; i<v+1; i++){
        if(dist[i] == INF) printf("INF\n");
        else printf("%d\n", dist[i]);
    }
    return 0;
}