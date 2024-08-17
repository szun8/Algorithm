#include<vector>
#include<queue>
using namespace std;
// 동서남북 방향으로 한칸씩 이동, map domain check
// 최단 거리 반환
int moveX[4] = {1,0,-1,0};
int moveY[4] = {0,1,0,-1};
int n, m;
vector<vector<int> > map;

struct Node{
    int x, y;
};
bool IsDomain(Node node){
    if(node.x>=0 && node.y>=0 && node.y<n && node.x<m) return true;
    else return false;
}

void BFS(Node node){
    queue<Node> q;
    q.push(node);
    while(!q.empty()){
        Node curNode = q.front();
        q.pop();
        for(int i=0; i<4;i++){
            Node nextNode;
            nextNode.x = curNode.x +moveX[i];
            nextNode.y = curNode.y +moveY[i];
            if(IsDomain(nextNode) && map[nextNode.y][nextNode.x] == 1){
                map[nextNode.y][nextNode.x] = map[curNode.y][curNode.x] +1;
                q.push(nextNode);
            }
        }
    }
}

// visited check is [y][x] > 1 = true
int solution(vector<vector<int> > maps)
{
    n = maps.size(); m=maps[0].size();
    map = maps;
    Node node;
    node.x = 0, node.y =0;
    BFS(node);
    
    int answer = map[n-1][m-1];
    if(answer == 1) answer = -1;
    return answer;
}