#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int bfs(vector<int> graph[], int now, int G, int F);
int main(){
    int f,s,g,u,d;
    cin>>f>>s>>g>>u>>d;
    vector<int> graph[f+1];

    for (int i = 1; i < f+1; i++) {
        int up = i + u;
        int down = i - d;
        if(up != i && up <= f) graph[i].push_back(up);
        if(down != i && down >= 1) graph[i].push_back(down);
    }
    bool isHere = false;
    for (int i = 1; i < f+1; i++) {
        if(find(graph[i].begin(),graph[i].end(),g)!=graph[i].end()){    // 도착층으로 가는 노드가 있으면
            isHere = true;
            break;
        }
    }
    if(isHere == false){
        cout<<"use the stairs";
        return 0;
    }
    int answer = bfs(graph, s, g, f);;
    if (answer==0) cout<<"use the stairs";
    else cout<<answer;
    
    return 0;
}

int bfs(vector<int> graph[], int now, int G, int F) {
    int floor[F+1];
    memset(floor,0,sizeof(floor));

    int cnt = 0;
    queue<int> q;
    q.push(now);
    floor[now] = 0;
    while (!q.empty()) {
        now = q.front();
        q.pop();
        for (int i = 0; i < graph[now].size(); i++) {
            int next = graph[now][i];
            if(next==G) {
                cnt = floor[now]+1;
                return cnt;
            }
            else if(floor[next]==0){    // 0이 아니면 이미 방문한 노드임 갈 필요없음
                q.push(next);
                floor[next] = floor[now]+1;
            }
        }
    }
    return cnt;
}