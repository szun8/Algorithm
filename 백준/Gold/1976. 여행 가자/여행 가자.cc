#include <iostream>
#include <vector>
using namespace std;
int n, m;

class DisjointSet{
private:
    vector<int> parent;
public:
    DisjointSet(int n) : parent(n+1){
        for(int i=0; i<n+1; i++){
            parent[i] = i;
        }
    }

    int Find(int x){
        if(parent[x] == x) return x;

        return parent[x]= Find(parent[x]);
    }

    void Merge(int i, int j){
        i = Find(i);
        j = Find(j);

        if(i == j) return;
        // 무조건 i밑으로 j를 넣는다
        parent[j] = i;
    }
};

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n>>m;

    DisjointSet disjointSet(n);
    vector<int> city(m+1);
    for(int i=1; i<n+1; i++){
        for(int j=1; j<n+1; j++){
            cin>>city[j];
            if(city[j]==1){
                disjointSet.Merge(i, j);
            }
        }
    }

    int planCity, bossCity = -1;
    for(int i=0; i<m; i++){
        cin>>planCity;
        if(bossCity == -1)
            bossCity = disjointSet.Find(planCity);
        else if(bossCity != disjointSet.Find(planCity)){
            printf("NO");
            return 0;
        }
    }
    printf("YES");
    return 0;
}