#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, x, y;

vector<int> children[101];  // 각 요소는 자식들을 저장한다
bool visited[101];
int answer = -1;

void FindFamily(int curCnt, int curNode){
    visited[curNode] = true;
    for(int i=0; i<children[curNode].size(); i++){
        if(children[curNode][i] == y){
            answer = curCnt;
            return;
        }
        else if(visited[children[curNode][i]]) continue;

        FindFamily(curCnt+1, children[curNode][i]);
    }
}

int main() {
    cin>>n>>x>>y>>m;
    if(x == y) {
        cout<<-1;
        return 0;
    }

    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        children[a].push_back(b);
        children[b].push_back(a);
    }

    FindFamily(1, x);    // (7), 3
    cout<<answer;

    return 0;
}

