#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class DisjointSet{
private:
    vector<int> parent;
    unordered_set<int> uniqueParent;
    
public:
    DisjointSet(int n) : parent(n+1){
        for(int i=0; i<=n; i++){
            parent[i] = i;
            uniqueParent.insert(i);
        }
    }
    int GetParentSize(){
        return uniqueParent.size()-1; // 0제외
    }
    
    int Find(int x){
        if(parent[x] == x) return x;
        
        return parent[x] = Find(parent[x]);
    }
    
    void Merge(int a, int b){
        a = Find(a);
        b = Find(b);
        
        if(a==b) return ;
        // a밑으로 b를 넣는다
        parent[b] = a;
        uniqueParent.erase(b);
    }
};

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    DisjointSet jointSet(n);
    for(int i=0; i<computers.size(); i++){
        for(int j=0; j<computers[j].size(); j++){
            if(computers[i][j] == 1) jointSet.Merge(i, j);
        }
    }
    return answer = jointSet.GetParentSize();
}