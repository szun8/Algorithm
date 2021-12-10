#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> score(n);
    for (int i = 0; i < n; i++) {
        cin>>score[i];
    }
    int min = *min_element(score.begin(),score.end());
    int max = *max_element(score.begin(),score.end());
    cout<<max-min;
    return 0;
}