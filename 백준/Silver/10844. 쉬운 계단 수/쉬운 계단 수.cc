#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

#define MOD 1000000000

int main() {
    int n; cin >> n;
    vector<vector<int>> stairs(n, vector<int>(10, 0));

    for (int i = 1; i < 10; i++) {
        stairs[0][i] = 1;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            if (j == 0) stairs[i][j] = stairs[i - 1][j + 1];
            else if (j == 9) stairs[i][j] = stairs[i - 1][j - 1];
            else stairs[i][j] = stairs[i-1][j-1] + stairs[i-1][j+1];

            stairs[i][j] %= MOD;
        }
    }

    int result = accumulate(stairs[n - 1].begin(), stairs[n - 1].end(), 0LL)%MOD;
    printf("%d", result);
    return 0;
}