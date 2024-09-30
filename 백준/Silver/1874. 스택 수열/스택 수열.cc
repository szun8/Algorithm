#include <iostream>
#include <stack>
#include <vector>
#define VAILD true
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n; cin >> n;
    stack<int> s;
    vector<char> print;

    int input, curTopNum = 1;
    for (int i = 0; i < n; i++) {
        cin >> input;

        while (VAILD) {
            if (s.empty() || s.top() < input) {
                s.push(curTopNum++);
                print.push_back('+');
            }

            if (s.top() == input) {
                s.pop();
                print.push_back('-');
                break;
            }

            if (curTopNum > input) {
                printf("NO");
                return 0;
            }
        }
    }

    for (int i = 0; i < print.size(); i++) printf("%c\n", print[i]);
    return 0;
}