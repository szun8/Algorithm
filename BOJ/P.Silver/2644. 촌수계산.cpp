#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int n, what1, what2, m;
vector<bool> check(n+1);
vector<int> rule(n+1);

int dfs(int what, vector<int> graph[]){
    stack<int> s;
    s.push(what);
    check[what] = true;
    while(!s.empty()){
        int current_node = s.top();
        s.pop();
        
        for (int i = 0; i < graph[current_node].size(); i++) {
            int next_node = graph[current_node][i];
            if(check[next_node]==false){    // 방문하지 않았다면,
                check[next_node]=true;
                s.push(current_node); s.push(next_node);
                if(next_node == what2) return s.size()-1;
                break;
            }
        }
    }
    return -1;
}
int main(){
    cin>>n;
    cin>>what1>>what2;
    cin>>m;
    vector<int> graph[n+1];

    fill(check.begin(),check.end(),false);  // 방문여부 false 초기화

    int a,b;
    for (int i = 0; i < m; i++) {
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    cout<<dfs(what1,graph);
    
    return 0;
}