#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool isTrue(pair<int, int> a, pair<int, int> b){ 
    // cmp함수의 인자로 정렬되는 변수의 pair<> 자료형을 가져올수있다!
    if(a.first!=b.first) return  a.first<b.first;
    else return a.second<b.second;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    scanf("%d",&n);
    vector< pair<int, int> > xy;
    for (int i = 0; i < n; i++)
    {
        int x,y;
        scanf("%d %d",&x, &y);
        xy.push_back(pair<int, int>(x,y));
    }

    sort(xy.begin(),xy.end(),isTrue);
    for (int i = 0; i < n; i++)
    {
        cout<<xy[i].first<<" "<<xy[i].second<<"\n";
        // endl은 언제나 무겁다 ^^...endl 수정으로 시간초과 해결
    }
    return 0;
}