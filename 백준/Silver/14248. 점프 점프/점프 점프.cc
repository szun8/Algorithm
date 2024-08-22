#include <vector>
#include <queue>
#include <iostream>

#define MAX 100000
std::vector<int> length[MAX];

int main() {
    std::vector<bool> visited;

    int n; scanf("%d", &n);
    visited.resize(n);

    for (int i = 0; i < n; i++) {
        int l;
        scanf("%d", &l);
        if(i - l >= 0)
            length[i].push_back(i - l);

        if (i + l < n)
            length[i].push_back(i + l);
    }

    int start;  scanf("%d", &start);

    std::queue<int> q;
    q.push(start-1);
    int answer = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        visited[cur] = true;

        for (int i = 0; i < length[cur].size(); i++) {
            if (visited[length[cur][i]]) continue;
            q.push(length[cur][i]);
        }
    }

    for (int i = 0; i < n; i++) {
        if (visited[i]) answer++;
    }

    printf("%d", answer);
    return 0;
}