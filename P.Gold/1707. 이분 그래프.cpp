#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int twice[20001];
bool isBipartite = true; // 이분 그래프이면 true. 아니면 false.

void dfs(int twice[], vector<int> graph[], int x){
    stack<int> s;
    s.push(x);
    twice[x]=3;
    while (!s.empty()) {
        int current = s.top();
        s.pop();
        for (int i = 0; i < graph[current].size(); i++) {
            int next = graph[current][i];
            if(twice[next]==0){ // 아직 미방문 노드라면,
                if(twice[current]==3){
                    twice[next]=4;
                }
                else if(twice[current]==4){
                    twice[next]=3;
                }
                s.push(current); s.push(next);
                break;
            }
            else if(twice[current]==twice[next]){   
                // 현재노드와 다음노드의 숫자는 항상 달라야 이분그래프 조건 만족
                isBipartite = false;
                return;
            }
        }
    }
}
int main(){
    int t;
    cin>>t;
    while (t--) {
        int v,e,start;
        cin>>v>>e;
        vector<int> graph[v+1];
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
        for (int i = 1; i < e; i++) {
            cin>>x>>y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        isBipartite = true;
        memset(twice,-1,sizeof(twice));
        fill(twice+1,twice+v+1,0);
        for (int i = 1; i < v+1; i++){
            if(twice[i]==0){
                dfs(twice,graph,i);
                // 모든 지점이 다 연결되어있지 않기떄문에 그 지점들까지 다 봐줘야함
            }            
        }
        if(isBipartite==true) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
