#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, m;
    cin>>n;

    map<int, int> cards;

    for(int i=0; i<n; i++){
        int num; cin>>num;
        map<int,int>::iterator existNum = cards.find(num);
        if(existNum!=cards.end()){
            existNum->second++;
        }
        else{
            cards.insert(pair<int,int>(num, 1));
        }
    }

    cin>>m;
    vector<int> exists(m, 0);
    for(int i=0; i<m; i++){
        int num; cin>>num;
        map<int,int>::iterator existNum = cards.find(num);
        if(existNum!=cards.end()){
            exists[i] = existNum->second;
        }
    }


    for(int i=0; i<m; i++){
        printf("%d ", exists[i]);
    }
    
    return 0;
}