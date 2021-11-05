#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    string num;
    cin>>num;
    for(int i=0;i<num.size();++i){
        if(num[i]=='-'){
            // 마이너스 다음인 수들의 +를 괄호로 묶어서 마이너스화 하기
            for(int z=i+1;z<num.size();z++){
                if(num[z]=='-') break;
                else if(num[z]=='+') num[z]='-';
                // 숫자면 그냥 넘어가기
            }
        }
    }
    
    int sum=0;
    string nums;
    int index1 = num.find_first_of('-');
    if (index1==-1) index1=99;
    int index2 = num.find_first_of('+');
    if (index2==-1) index2=99;
    int index;
    if(index1>=index2)  { // index2 전의 숫자들을 다 더해줘야함.
        for(int i=0;i<index2;i++){
            nums.push_back(num[i]);
        }
        sum = stoi(nums);
        index=index2;
    }
    else if (index1<index2){
        for(int i=0;i<index1;i++){
            nums.push_back(num[i]);
        }
        sum = stoi(nums);
        index=index1;
    }

    for(int i=index;i<num.size();i++){
        nums.clear();
        
        if(num[i]=='-'){
            for(int j=i+1; ;j++){
                if(num[j]<=57 && num[j]>=48)
                nums.push_back(num[j]);
                else break;
            }
            int n = stoi(nums);
            sum-=n;
        }
        else if(num[i]=='+'){
            for(int j=i+1; ;j++){
                if(num[j]<=57 && num[j]>=48)
                nums.push_back(num[j]);
                else break;
            }
            int n = stoi(nums);
            sum+=n;
        }
    }
    cout<<sum;
    return 0;
}