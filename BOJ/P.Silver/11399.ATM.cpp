#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> times(n);
    for (int i = 0; i < n; i++)
    {
        cin>>times[i];
    }
    stable_sort(times.begin(),times.end());
    int time=0;
    for (int i = 0; i < n; i++)
    {
        time+=accumulate(times.begin(),times.end()-i,0);
    }
    cout << time;
    return 0;
}