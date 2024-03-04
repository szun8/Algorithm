#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> dfs(int start, vector<int> graph[], vector<bool> check, vector<int> rule){
    stack<int> s;
    s.push(start);
    check[start] = true;
    while(!s.empty()){
        int current_node = s.top();
        s.pop();
        
        for (int i = 0; i < graph[current_node].size(); i++)
        {
            int next_node = graph[current_node][i];
            if(check[next_node]==false){    // 방문하지 않았다면,
                check[next_node]=true;
                s.push(current_node); s.push(next_node);
                break;
            }
        }
        if(!s.empty() && rule[s.top()]==0){
            rule[s.top()] = current_node;
        }
    }
    return rule;
}
int main(){
    int n,count = 0;
    cin>>n;
    vector<int> graph[n+1];
    vector<bool> check(n+1);
    vector<int> rule(n+1);
    fill(check.begin(),check.end(),false);  // 방문여부 false 초기화
    check[0] = true;

    int a,b;
    for (int i = 0; i < n-1; i++)
    {
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 0; i < n; i++)
    {
        sort(graph[i].begin(),graph[i].end());
    }

    rule = dfs(1,graph,check,rule);
    for (int i = 2; i < rule.size(); i++)
    {
        cout<<rule[i]<<"\n";
    }
    return 0;
}