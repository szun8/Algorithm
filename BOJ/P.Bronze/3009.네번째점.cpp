#include <iostream>
#include <map>
using namespace std;

int main(){
    map<int,int> numX;
    map<int,int> numY;
    int x,y;
    for(int i=0;i<3;i++){
        cin >> x >> y;
        map<int,int>::iterator iterX = numX.find(x);
        if(iterX!=numX.end()){
            // 만약 나왔던 좌표라면,
            iterX->second++;
        }
        else {
            numX.insert(pair<int,int> (x,1));
        }

        map<int,int>::iterator iterY = numY.find(y);
        if(iterY!=numY.end()){
            // 만약 나왔던 좌표라면,
            iterY->second++;
        }
        else {
            numY.insert(pair<int,int> (y,1));
        }
    }

    for(map<int,int>::iterator iter = numX.begin();iter!=numX.end();++iter){
        if(iter->second==1) x=iter->first;
    }
    for(map<int,int>::iterator iter = numY.begin();iter!=numY.end();++iter){
        if(iter->second==1) y=iter->first;
    }

    cout << x << " " << y;
    return 0;
}