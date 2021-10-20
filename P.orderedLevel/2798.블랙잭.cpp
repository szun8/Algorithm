#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> card;
    vector<int> sums;
    for(int i = 0;i<n;++i){
        int cardNum;
        cin >> cardNum;
        card.push_back(cardNum);
    }
    sort(card.begin(),card.end()); // 오름차순으로 정렬
    int sum = 0;
    for(int i =0;i<n;++i){
        for(int j =0;j<n;++j){
            for(int z =0;z<n;++z){
                if(i==z||i==j||j==z);
                else {
                    sum = card[i]+card[j]+card[z];
                    if(sum<=m) sums.push_back(sum);
                }
            }
        }
    }
    sum = *max_element(sums.begin(),sums.end());
    cout<< sum;
    return 0;
}