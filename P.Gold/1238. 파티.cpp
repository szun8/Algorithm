#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1e9
using namespace std;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,M,X; cin>>N>>M>>X;
    int comeDist[N+1];  // X의 마을에서 자기의 마을로 가는 최소 거리
    bool visited[N+1];
    fill(visited,visited+N+1,false);
    fill(comeDist,comeDist+N+1,INF);
    fill(visited,visited+N+1,false);
    vector<pair<int,int> > path[N+1];

    // input
    for (int i = 0; i < M; i++) {
        int from,to,val; cin>>from>>to>>val;
        path[from].push_back(pair<int,int>(to, val));
    }
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > ing;

    // X마을 -> 자기마을
    comeDist[X]=0;
    ing.push(pair<int,int>(0, X));  // cost, here
    while (!ing.empty()) {
       int here = ing.top().second;
       int cost = ing.top().first;
       ing.pop();
       if(!visited[here]){
           visited[here]=true;
           for (int i = 0; i < path[here].size(); i++) {
               int nCost = path[here][i].second;
               int next = path[here][i].first;
               if(comeDist[next] > cost + nCost){
                   comeDist[next] = cost + nCost;
                   ing.push(pair<int,int>(comeDist[next],next));
                }
            }
        }
    }
    // 자기마을 -> X마을
    for (int i = 1; i < N+1; i++) {
        if(i==X) continue;
        int goDist[N+1];    // 자기의 마을에서 X의 마을로 가는 최소 거리
        fill(goDist,goDist+N+1,INF);
        fill(visited,visited+N+1,false);
        goDist[i]=0;
        ing.push(pair<int,int>(0, i));  // cost, here
        while (!ing.empty()) {
            int here = ing.top().second;
            int cost = ing.top().first;
            ing.pop();
            if(!visited[here]){
                visited[here]=true;
                for (int i = 0; i < path[here].size(); i++) {
                    int nCost = path[here][i].second;
                    int next = path[here][i].first;
                    if(goDist[next] > cost + nCost){
                        goDist[next] = cost + nCost;
                        ing.push(pair<int,int>(goDist[next],next));
                    }
                }
            }
        }
        comeDist[i]+=goDist[X];
    }
    // output
    cout<<*max_element(comeDist+1,comeDist+N+1);
    return 0;
}