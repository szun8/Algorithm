#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string strA, strB, strC;
    cin >> strA >> strB >> strC;

    int lcs[101][101][101] = {0,};
    for (int i = 1; i < strA.length() + 1; i++) {
        for (int j = 1; j < strB.length() + 1; j++) {
            for (int z = 1; z < strC.length() + 1; z++) {
                if (strA[i - 1] == strB[j - 1] && strB[j - 1] == strC[z - 1]) {
                    lcs[i][j][z] = lcs[i - 1][j - 1][z - 1] +1;
                }
                else {
                    lcs[i][j][z] = max({ lcs[i - 1][j][z] ,lcs[i][j - 1][z] ,lcs[i][j][z - 1] });
                }
            }
        }
    }

    printf("%d", lcs[strA.length()][strB.length()][strC.length()]);
    return 0;
}