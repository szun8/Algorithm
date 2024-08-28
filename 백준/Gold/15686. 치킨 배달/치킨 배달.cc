#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

struct Coord {
    int r, c;
};
int n, m, answer = -1;
vector<Coord> house, chicken, selectedChicken;

int CalDist(Coord a, Coord b) {
    return abs(a.r - b.r) + abs(a.c - b.c);
}

void CalMinDist() {
    int curDists = -1;
    for (int i = 0; i < house.size(); i++) {
        int min = -1;
        for (int j = 0; j < selectedChicken.size(); j++) {
            int tmp = CalDist(house[i], selectedChicken[j]);
            if (min == -1 || tmp < min) {
                min = tmp;
            }
        }
        curDists += min;
    }
    if (curDists != -1) {
        if (answer == -1 || curDists < answer) answer = curDists + 1; // -1로 시작해서 0 보간
    }
}

bool choosed[13];
void ChooseChicken(int curChicken, int chooseCnt) {
    if (chooseCnt == m) CalMinDist();

    for (int i = curChicken; i < chicken.size();  i++) {
        if (choosed[i]) continue;

        choosed[i] = true;
        selectedChicken.push_back({ chicken[i].r, chicken[i].c });
        ChooseChicken(i, chooseCnt + 1);
        choosed[i] = false;
        selectedChicken.pop_back();
    }
}


int main() {
    cin >> n >> m;
    // nCm의 경우의 수 파악 필요
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int input; cin >> input;
            if (input == 1) house.push_back({ i, j });
            else if (input == 2) chicken.push_back({ i, j });
        }
    }
    ChooseChicken(0, 0);

    printf("%d", answer);
    return 0;
}