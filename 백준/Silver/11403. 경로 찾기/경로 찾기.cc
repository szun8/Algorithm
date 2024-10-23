#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> graph;

vector<vector<int>> FlowdWarshall() {
    vector<vector<int>> dist = graph;
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] == 1 && dist[k][j] == 1)
                    dist[i][j] = 1;
            }
        }
    }
    return dist;
}

void Print(vector<vector<int>> printGraph) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (printGraph[i][j] == 0) printf("0 ");
            else printf("1 ");
        }
        printf("\n");
    }
}

int main() {
    cin >> n;
    graph.resize(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    Print(FlowdWarshall());
}