#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    bool square[100][100] = {false, };
    for (int i = 0; i < n; i++) {
        int w,h;
        cin>>w>>h;
        for (int j = h-1; j < h+9; j++) {
            fill(&square[j][w-1], &square[j][w+9],true);
        }
    }
    int how = count(&square[0][0], &square[99][0]+100,true);
    cout<<how;
    return 0;
}