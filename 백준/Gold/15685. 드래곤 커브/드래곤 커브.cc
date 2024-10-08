#include <iostream>
#include <unordered_map>
#include <vector>
#include <cstdlib>
using namespace std;
struct DragonCurve {
    int x, y;
    int dir;
    int generation;
};

struct Point {
    int x, y;
    Point() {}
    Point(int _x, int _y) : x(_x), y(_y) {}
};

vector<Point*> rule = { new Point(1,0), new Point(0,-1), new Point(-1,0), new Point(0,1) };

unordered_map<int, Point*> rule_x = { pair<int, Point*>(1, new Point(1, -1)), pair<int, Point*>(-1, new Point(-1, 1)) };
unordered_map<int, Point*> rule_y = { pair<int, Point*>(-1, new Point(-1, -1)), pair<int, Point*>(1, new Point(1, 1)) };

bool CheckArea(int y, int x) {
    if (y + 1 < 101 && x + 1 < 101) return true;
    else return false;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    DragonCurve m_dragonCurve;
    vector < vector<bool>> coord(101, vector<bool>(101, false));

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> m_dragonCurve.x >> m_dragonCurve.y >> m_dragonCurve.dir >> m_dragonCurve.generation;

        coord[m_dragonCurve.y][m_dragonCurve.x] = true;
        vector<Point*> selectPointList = { new Point(m_dragonCurve.x, m_dragonCurve.y) };

        for (int curGen = 0; curGen <= m_dragonCurve.generation; curGen++) {
            Point curLastPoint = *selectPointList[selectPointList.size() - 1];

            vector<Point*> preSelectPointList = selectPointList;
            for (int idx = preSelectPointList.size() - 1; idx >= 0; idx--) {
                Point* tmpPoint = new Point();
                Point* point = preSelectPointList[idx];
                if (preSelectPointList.size() == 1) {
                    tmpPoint->x = point->x + rule[m_dragonCurve.dir]->x;
                    tmpPoint->y = point->y + rule[m_dragonCurve.dir]->y;
                }
                else if (point->x == curLastPoint.x && point->y == curLastPoint.y) continue;
                else {  // Find vector from curPoint to lastPoint
                    int _x = curLastPoint.x - point->x;
                    int _y = curLastPoint.y - point->y;

                    // Find moved point by Rotating 90 
                    if (_x == 0) {
                        _x = rule_y[_y / abs(_y)]->x * abs(_y) + point->x;
                        _y = rule_y[_y / abs(_y)]->y * abs(_y) + point->y;
                    }
                    else if (_y == 0) {
                        _y = rule_x[_x / abs(_x)]->y * abs(_x) + point->y;
                        _x = rule_x[_x / abs(_x)]->x * abs(_x) + point->x;
                    }
                    else {
                        int tmpX = _x;
                        _x = rule_x[_x / abs(_x)]->x * abs(_x) + rule_y[_y / abs(_y)]->x * abs(_y) + point->x;
                        _y = rule_x[tmpX / abs(tmpX)]->y * abs(tmpX) + rule_y[_y / abs(_y)]->y * abs(_y) + point->y;
                    }
                    coord[_y][_x] = true;

                    tmpPoint->x = _x;
                    tmpPoint->y = _y;
                }
                coord[tmpPoint->y][tmpPoint->x] = true;
                selectPointList.push_back(tmpPoint);
            }
        }
    }

    int result = 0;
    for (int i = 0; i < coord.size(); i++) {
        for (int j = 0; j < coord[i].size(); j++) {
            if (coord[i][j] && CheckArea(i, j)) {
                if (coord[i][j + 1] && coord[i + 1][j] && coord[i + 1][j + 1]) 
                {   // 오른쪽           아래               대각선
                    result++;
                }
            }
        }
    }

    printf("%d", result);
    return 0;
}