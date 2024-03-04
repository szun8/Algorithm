#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> paper(2, 0);
vector<vector<int> > colorPaper;
// [0] blue & [1] white
bool Find(int x, int y, int size, int what){
    bool result = false;

    for(int i=0; i<size; i++){
        if(find(colorPaper[y+i].begin()+x,  colorPaper[y+i].begin()+x+size, what) == colorPaper[y+i].begin()+x+size){
            // ex. 1을 찾는데 last가 나오면 1이 없다는 소리 => 0으로 가득찼다
            result = true;
        }
        else {
            return false;
        }
    }
    ++paper[what];
    return true;
}

void CutPaper(int x, int y, int size){
    if(!Find(x, y, size, 0) && !Find(x, y, size, 1)){
        // 0과 1이 둘다 존재하기에 해당 영역을 4등분시키며 재귀한다.
        int halfSize = size/2;
        CutPaper(x, y, halfSize);                  // 1사분면
        CutPaper(x+halfSize, y, halfSize);         // 2사분면
        CutPaper(x, y+halfSize, halfSize);         // 3사분면
        CutPaper(x+halfSize, y+halfSize, halfSize);// 4사분면
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin>>n;
    colorPaper.resize(n, vector<int>(n));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>colorPaper[i][j];
        }
    }
    CutPaper(0, 0, n);
    printf("%d\n%d", paper[1], paper[0]);
    return 0;
}