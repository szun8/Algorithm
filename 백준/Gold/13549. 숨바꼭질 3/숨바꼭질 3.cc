#include <iostream>
#include <queue>
#include <deque>
#include <limits>
using namespace std;

#define INF numeric_limits<int>::max()
#define MAX 100001
int n,k;
deque<pair<int, int>> dq;
//priority_queue<pair<int, int>, vector<pair<int, int> >,  greater<pair<int, int> > > pq; // weight, node
//bool nodeInfo[MAX];  // node, weight -> 각 경로의 최단을 기록
int times[MAX];

void Dijkstra(){
    fill(times, times+MAX, INF);
    dq.push_back({0, n});
    //pq.push({0, n});
    times[n] = 0;

    int curNode, curWeight;
    while(!dq.empty()){
        curNode = dq.front().second;
        curWeight = dq.front().first;
        dq.pop_front();

        if(curNode == k){
            printf("%d", curWeight);
            return;
        }

        if(curNode +1 < MAX && times[curNode +1] > curWeight+1){
            dq.push_back({curWeight+1, curNode+1});
            times[curNode+1] = curWeight+1;
        }
        if(curNode -1 >= 0 && times[curNode -1]> curWeight+1){
            dq.push_back({curWeight+1, curNode-1});
            times[curNode -1] = curWeight+1;
        }
        if(curNode *2 < MAX && times[curNode *2] > curWeight){
            dq.push_front({curWeight, curNode*2});
            times[curNode*2] = curWeight;
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