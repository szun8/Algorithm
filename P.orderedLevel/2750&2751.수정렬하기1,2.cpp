#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n,num;;
    cin >> n;
    vector<int> numvec;
    // endl 시간 너무 잡아먹음

    for(int i=0;i<n;++i){
        cin>>num;
        numvec.push_back(num);
    }
    sort(numvec.begin(),numvec.end());
    for(int i =0;i<numvec.size();++i){
        cout<<numvec[i]<<"\n";
    }
    return 0;
}


// #include <set>
// set<int> numset;
//     for(int i=0;i<n;++i){
//         int num;
//         cin>>num;
//         numset.insert(num);
//     }
//     for ( set<int>::iterator iter = numset.begin();iter!=numset.end();iter++){
//         cout<<*iter<<endl;
//     }