#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n, m; cin>>n>>m;

    int rowSum = 0;
    vector<vector<int> > table(n);
    for(int i=0; i<n*n; i++){
        int input; cin>>input;
        rowSum += input;
        table[i/n].push_back(rowSum);
        if(i%n==n-1) rowSum = 0;
    }

    for(int i=0; i<m; i++){
        int x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;

        int sum = 0;
        if(y1 == 1){    // 앞에 뺄게 없는 경우 == 처음부터 특정 부분까지의 합
            for(int j=x1-1; j<x2; j++){
                sum+=table[j][y2-1];
            }
        }
        else{
            for(int j=x1-1; j<x2; j++){
                sum+=(table[j][y2-1]-table[j][y1-2]);
            }
        }
        printf("%d\n", sum);
    }

    return 0;
}