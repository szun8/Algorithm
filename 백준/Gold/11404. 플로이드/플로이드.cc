#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>> graph;

vector<vector<int>> FlowdWarshall() {
    vector<vector<int>> dist = graph;
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] != 0 && dist[k][j] != 0)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    return dist;
}

void Print(vector<vector<int>> printGraph) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j || printGraph[i][j] == 1e9) printf("0 ");
            else printf("%d ", printGraph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    cin >> n >> m;
    graph.resize(n+1, vector<int>(n+1, 1e9));

    int from, to, weight;
    for (int i = 0; i < m; i++) {
        cin >> from >> to >> weight;
        if(graph[from][to] > weight)
            graph[from][to] = weight;
    }

    Print(FlowdWarshall());
}