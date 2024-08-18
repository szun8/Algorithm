#include <iostream>
#include <queue>
using namespace std;
long long a,b,answer;
bool isOk = false;
class CountNumber{
public:
    long long num, cnt;
    CountNumber(long long n, long long c){
        num=n; cnt=c;
    }
};
queue<CountNumber> number;

void BFS(){
    while(!number.empty()){
        long long num = number.front().num;
        long long cnt = number.front().cnt;
        number.pop();
        CountNumber cntnum1(num*2,cnt+1);
        if(cntnum1.num==b){
            isOk=true;
            answer=cnt;
            return ;
        }
        else if(cntnum1.num < b) number.push(cntnum1);
        CountNumber cntnum2((num*10)+1,cnt+1);
        if(cntnum2.num==b){
            isOk=true;
            answer=cnt;
            return ;
        }
        else if(cntnum2.num < b) number.push(cntnum2);
    }
}
int main(){
    cin>>a>>b;
    if(a==b) {
        cout<<1;
        return 0;
    }
    CountNumber cntnum(a,1);
    number.push(cntnum);
    BFS();
    if(isOk==true) cout<<answer+1;
    else cout<<-1;
}