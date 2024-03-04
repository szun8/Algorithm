#include <iostream>
#include <vector>
using namespace std;

int main(){
    int input;
    cin >> input;

    int count=0;
    int nums[3];

    for(int i = 1; i <= input ; ++i){
        if(i < 100) count=i;
        else if(i==1000) break;
        else{
            int num = i;
            int j=0;
            while(num>0){
                nums[j]=num%10;
                j++;
                num/=10;
            }
            if(nums[0]-nums[1]==nums[1]-nums[2]) count++;
        }
    }

    cout<<count;
    return 0;
}