#include <iostream>
#include <algorithm>
#include <vector>
// LOVE printf && scanf ...
int main(){
    int n;
    scanf("%d", &n);
    std::vector<int> numvec;
    for(int i =0;i<n;++i){
        int num;
        scanf("%d", &num);
        numvec.push_back(num);
    }
    int m;
    scanf("%d", &m);

    for(int i =0;i<m;i++){
        int Qnum;
        scanf("%d", &Qnum);
        if(find(numvec.begin(),numvec.end(),Qnum)!=numvec.end()){
            printf("1\n");
        }
        else    printf("0\n");
    }
    return 0;
}