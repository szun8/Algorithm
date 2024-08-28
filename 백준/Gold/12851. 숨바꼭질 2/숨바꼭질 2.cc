#include <queue>
#include <iostream>
#include <cstring>
using namespace std;

int resultCnt, resultSec;
struct Node {
    int num, sec;
};

void BFS(int start, int end) {
    bool visited[100001];
    memset(visited, false, sizeof(visited));

    queue<Node> q;
    q.push({ start, 0 });

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();
        visited[cur.num] = true;

        if (cur.num == end) {
            if (resultSec == -1) {
                resultSec = cur.sec;
                resultCnt++;
            }
            else if (cur.sec == resultSec)
                resultCnt++;
        }
        else {
            if (resultSec == -1 || cur.sec + 1 <= resultSec) {
                if (cur.num * 2 >= 0 && cur.num * 2 < 100001 && !visited[cur.num * 2]) q.push({ cur.num * 2 , cur.sec + 1 });
                if (cur.num + 1 >= 0 && cur.num + 1 < 100001 && !visited[cur.num + 1]) q.push({ cur.num + 1 , cur.sec + 1 });
                if (cur.num - 1 >= 0 && cur.num - 1 < 100001 && !visited[cur.num - 1]) q.push({ cur.num - 1 , cur.sec + 1 });
            }
        }
    }
}

int main() {
    int n, k; cin >> n >> k;
    resultCnt = 0;
    resultSec = -1;
    if (n == k) {
        cout << "0\n1";
        return 0;
    }
    BFS(n, k);

    cout << resultSec << "\n" << resultCnt;
    return 0;
}