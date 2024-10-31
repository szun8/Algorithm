#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int v, e;
struct Edge {
    int from, to, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};
vector<Edge> edges;

class UnionSet {
private:
    vector<int> parent, rank;

public:
    UnionSet(int n) : parent(n+1), rank(n+1, 1) {
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    int Find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = Find(parent[x]);
    }

    void Merge(int a, int b) {
        a = Find(a);
        b = Find(b);

        if (a == b) return;

        if (rank[a] > rank[b]) 
            swap(a, b);

        parent[a] = b;
        if (rank[a] == rank[b])
            rank[b]++;
    }
};

int Kruscal(int n) {
    sort(edges.begin(), edges.end());
    UnionSet unionSet(n);
    int result = 0;

    for (Edge& e : edges) {
        if (unionSet.Find(e.from) != unionSet.Find(e.to)) {
            unionSet.Merge(e.from, e.to);
            result += e.weight;
        }
    }
    return result;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> v >> e;
    int f, t, w;
    for (int i = 0; i < e; i++) {
        cin >> f >> t >> w;
        edges.push_back({ f, t, w });
    }
    printf("%d", Kruscal(v));
    return 0;
}