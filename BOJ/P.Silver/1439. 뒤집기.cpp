#include <iostream>
#include <algorithm>    // count()
using namespace std;
int main(){
    string s; cin>>s;   // 문자열 입력
    int zerocnt=0, onecnt=0;
    int zero = count(s.begin(),s.end(),'0');
    int one = s.size()-zero;
    // 0을 바꿨을때의 경우의수 vs 1을 바꿨을때의 경우의수
    for (int i = 0; i < s.size(); i++) {
        if(s[i]=='0'){
            while(s[i+1]=='0') {
                i++;
            }
            zerocnt++;
        }
    }
    for (int i = 0; i < s.size(); i++) {
        if(s[i]=='1'){
            while(s[i+1]=='1') {
                i++;
            }
            onecnt++;
        }
    }
    // 둘 중 작은 것을 출력
    zerocnt>onecnt ? cout<<onecnt : cout<<zerocnt;
    return 0;
}