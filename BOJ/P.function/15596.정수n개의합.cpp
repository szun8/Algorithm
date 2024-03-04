#include <vector>
#include <numeric>
using namespace std;

long long sum(vector<int> &a){
    long long ans = 0;
    return ans = accumulate(a.begin(),a.end(),0LL);
}