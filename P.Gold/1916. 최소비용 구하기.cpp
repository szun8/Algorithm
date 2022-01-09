#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9 // dist 배열에 저장한 무한대 정의
using namespace std;
 
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,M; cin>>N>>M;  // 도시의수, 버스의 수
    vector<pair<int,int> > arr[N+1];    // 각 노드에 연결된 [정점, 비용] 저장할 배열
    bool visited[N+1];
    fill(visited,visited+N+1,false);
    
    for(int i=0;i<M;i++){
        int from,to,val;    // from에서 to까지 걸리는 비용 val
        cin>>from>>to>>val; // 각 경로 정보 입력
        arr[from].push_back(pair<int,int>(to,val));
    }
    
    int dist[N+1];              // 시작점에서 각 노드까지의 최단거리를 저장해주는 배열
    fill(dist,dist+N+1,INF);    // 모든 거리의 비용을 최대로 설정
    priority_queue< pair<int,int> ,vector<pair<int,int> >,greater<pair<int,int> > > qu;
    // 작은 비용을 가진 정점으로 자동 정렬되는! -> [from에서 to까지의 비용, to정점]

    int start, end; cin>>start>>end;    // 출발점, 도착점
    
    qu.push(pair<int,int>(0,start));    // 출발점 저장 
    dist[start]=0;    // 시작점의 최단거리 (자기 자신까지의 거리 = 0)
    
    while(!qu.empty()){
        int cost = qu.top().first;    // 현재 탐색할 정점의 비용
        int here = qu.top().second;   // 현재 탐색할 정점의 번호
        qu.pop();
        if(!visited[here]){           // 이미 방문한 정점은 pass
            visited[here]=true;
            if(here==end) continue;   // 도착점이라면 pass
                
            for(int i=0; i<arr[here].size(); i++){  
                // 현재 정점에서 연결된 정점들까지의 비용 탐색
                int next = arr[here][i].first;
                int nextCost = arr[here][i].second;
                
                if(dist[next] > dist[here] + nextCost){    
                    // 여기까지 온 거리가 다른 경우보다 최단이라면, 갱신
                    dist[next] = dist[here] + nextCost;
                    qu.push(pair<int,int>(dist[next],next));
                }
            }
        }
    }
    cout<<dist[end];
    return 0;
}