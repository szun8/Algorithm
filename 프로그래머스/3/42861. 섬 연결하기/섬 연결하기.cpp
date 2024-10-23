#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge{
    int from, to, weight;
    bool operator<(const Edge& other) const{
        return weight < other.weight;
    }
};
vector<Edge> edges;

class UnionFind{
    vector<int> parent, rank;
public:
    UnionFind(int n) : parent(n), rank(n,1){
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
    }
    
    int Find(int x){
        if(parent[x] == x) return x;
        return parent[x] = Find(parent[x]);
    }
    
    void Merge(int from, int to){
        from = Find(from);
        to = Find(to);
        
        if(from == to) return;
        
        if(rank[from] < rank[to])
            swap(from, to);
        
        parent[to] = from;
        if(rank[from] == rank[to])
            rank[from]++;
    }
};

int Kruscal(int n){
    sort(edges.begin(), edges.end());
    UnionFind uf(n);
    int result = 0;
    for(Edge& e : edges){
        if(uf.Find(e.from) != uf.Find(e.to)){
            uf.Merge(e.from, e.to);
            result+=e.weight;
        }
    }
    return result;
}

int solution(int n, vector<vector<int>> costs) {
    for(int i=0; i<costs.size(); i++){
        edges.push_back({costs[i][0], costs[i][1], costs[i][2]});
    }
    
    return Kruscal(n);
}