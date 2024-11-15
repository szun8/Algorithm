#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    vector<int> lis;

    for (int i = 0; i < v.size(); i++) {
        int lo = lower_bound(lis.begin(), lis.end(), v[i]) - lis.begin();

        if (lo == lis.size()) lis.push_back(v[i]);
        else lis[lo] = v[i];
    }

    printf("%d", lis.size());
    return 0;
}