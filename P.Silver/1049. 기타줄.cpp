#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    vector<int> set;
    vector<int> one;
    int n,m,total=0; cin>>n>>m;
    while (m--) {
        int s,o; cin>>s>>o;
        set.push_back(s);
        one.push_back(o);
    }
    // 제일 저렴한 것들순으로 정렬
    sort(set.begin(),set.end());
    sort(one.begin(),one.end());

    int onetosix = one[0]*6;
    if(onetosix>set[0]){
        // 낱개로 사는게 더 비싼경우,
        while(n>=6){    // set로 돌만큼 구매
            total+=set[0];
            n-=6;
        }
        int priceOne=0, priceSet=set[0];
        while(n>0){     // 일단 나머지 낱개로 구매
            priceOne+=one[0];
            --n;
        }
        // 나머지 낱개 구매금액보다 걍 세트구매한 금액이 더 싸면 세트로 구매 처리
        priceOne > priceSet ? total+=priceSet : total+=priceOne;
    }
    else {  // 낱개로 사는게 더 싼 경우,
        while(n>0){     // 나머지 낱개로 구매
            total+=one[0];
            --n;
        }
    }
    cout<<total;
    return 0;
}