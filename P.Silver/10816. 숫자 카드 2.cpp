#include <iostream>
#include <algorithm>    // upper_bound & lower_bound
#include <vector>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin>>n;
    vector<int> have(n+1);
    for (int i = 0; i < n; i++)
    {
        cin>>have[i];
    }
    have[n]=*max_element(have.begin(),have.end())+1;
    // upper_bound의 초과하는 index를 위해 크기를 하나더 크게 설정
    sort(have.begin(),have.end());

    int m;
    cin>>m;
    int card[m];
    for (int i = 0; i < m; i++)
    {
        int what;
        cin>>what;

        vector<int>::iterator upIndex = upper_bound(have.begin(),have.end(),what);
        // 찾으려는 key값을 처음으로 넘는(초과하는) 숫자의 위치 반환
        vector<int>::iterator downIndex = lower_bound(have.begin(),have.end(),what);
        // 찾으려는 key값보다 같거나 큰 숫자의 위치 반환

        cout<<(upIndex-have.begin()) - (downIndex-have.begin())<<" ";
        // index 접근을 위해 have.begin() 뺴주기
    }
    return 0;
}