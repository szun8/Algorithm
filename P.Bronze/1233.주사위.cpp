#include <iostream>
#include <map>
using namespace std;

int main(){
    int s1,s2,s3;
    cin >> s1 >> s2 >> s3;
    map<int, int> sums;
    for(int i =1;i<=s1;i++){
        for (int j = 1; j <= s2; j++){
            for(int z = 1; z<=s3 ; z++){
                int sum =i+j+z;
                map<int, int>::iterator iter = sums.find(sum);
                if(iter!=sums.end()){  // 합이 있으면
                    iter->second++;
                }
                else if(iter==sums.end()) {    // 합이 없으면
                    sums.insert(pair<int,int>(sum,1));
                }
            }
        }
    }
    int max=0;
    int count;
    for(map<int,int>::iterator iter = sums.begin();iter!=sums.end();iter++){
        if(max<iter->second) {
            max = iter->second;
            count = iter->first;
        }
    }
    cout << count;

    return 0;
}