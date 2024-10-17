#include <iostream>
#include <queue>
using namespace std;

#define MAX 100001
int n,k;
bool nodeInfo[MAX];  // node, weight -> 각 경로의 최단을 기록

void Dijkstra(){
    priority_queue<pair<int, int>, vector<pair<int, int> >,  greater<pair<int, int> > > pq; // weight, node
    
    pq.push({0, n});
    nodeInfo[n] = true;

    int curNode, curWeight;
    while(!pq.empty()){
        curNode = pq.top().second;
        curWeight = pq.top().first;
        pq.pop();

        if(curNode == k){
            printf("%d", curWeight);
            return;
        }

        if(curNode *2 < MAX && !nodeInfo[curNode *2]){
            pq.push({curWeight, curNode*2});
            nodeInfo[curNode*2] = true;
        }

        if(curNode +1 < MAX && !nodeInfo[curNode +1]){
            pq.push({curWeight+1, curNode+1});
            nodeInfo[curNode+1] = true;
        }

        if(curNode -1 >= 0 && !nodeInfo[curNode -1]){
            pq.push({curWeight+1, curNode-1});
            nodeInfo[curNode-1] = true;
        }
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n>>k;
    Dijkstra();
    return 0;
}