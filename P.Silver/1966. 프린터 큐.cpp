#include <iostream>
#include <deque>
using namespace std;

class What {
public:
    int index;
    int importance;

public:
    What(int x, int m){
        index = x;
        importance = m;
    }
};

int MAX(deque<What> thing){
    int max=-1;
    for (int i = 0; i < thing.size(); i++) {
        if(thing[i].importance>max) max = thing[i].importance;
    }
    return max;
}

int main(){
    int t;
    cin>>t;
    while (t--) {
        int n, m, much, num=0;
        cin>>n>>m; // m번째 문서가 몇번째 출력되는가?
        deque<What> print;
        for (int i = 0; i < n; i++) {
            cin>>much;
            What thing(i,much);
            print.push_back(thing);
        }
        while (!print.empty()) {
            if(print[0].importance == MAX(print)){
                ++num;
                if(print[0].index==m) {
                    cout<<num<<"\n";
                    break;
                }
                print.pop_front();
            }
            else{
                print.push_back(print.front());
                print.pop_front();
            }
        }
    }
    return 0;
}