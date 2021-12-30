#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;
int main(){
    int n,l,h; // n명, 최저점 l개, 최고점 h개
    cin>>n>>l>>h;
    vector<int> movie(n);
    for (int i = 0; i < n; i++) cin>>movie[i];
    sort(movie.begin(),movie.end());    //오름차순
    int sum = accumulate(movie.begin()+l,movie.end()-h,0);
    cout<<fixed;
    cout.precision(10);
    cout<<(double)sum/(n-l-h);
    return 0;
}