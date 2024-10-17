#include <iostream>
#include <vector>
using namespace std;

int n, m;

class UnionSet {
private:
    vector<int> parent;
    vector<int> rank;

public:
    UnionSet(int n) : parent(n+1), rank(n+1, 1) {
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int Find(int x) {
        if (parent[x] == x) return x;

        return parent[x] = Find(parent[x]);
    }

    bool Find(int a, int b) {
        if (Find(a) == Find(b)) return true;
        else return false;
    }

    void Merge(int a, int b) {
        a = Find(a);
        b = Find(b);

        if (a == b) return;

        // 더 높이가 긴 집합 아래로 높이가 짧은 집합을 합친다.
        // -> 무조건 b의 아래로 a를 넣는다

        if (rank[a] > rank[b]) 
            swap(a, b);

        parent[a] = b;
        if (rank[a] == rank[b])
            rank[b]++;
    }
};



int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;

    UnionSet unionSet(n);
    
    int type, a, b;
    for (int i = 0; i < m; i++) {
        cin >> type >> a >> b;
        if (type == 0) {
            unionSet.Merge(a, b);
        }
        else {
            if (unionSet.Find(a, b)) printf("yes\n");
            else printf("no\n");
        }
    }
    
    return 0;
}