#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;

    for (int i = 0; i < babbling.size(); i++)
    {
        string origin = babbling[i];
        while(babbling[i]!=""){
            if(babbling[i].length()<2) { // 맞출수 있는 문자가 없는 경우
                if(i < babbling[i].length()-1) origin = babbling[++i];
                else break;  // 문자의 마지막인 경우 코어 덤프가 날수 있기에 break하고 while문 종료
            }
            if(babbling[i].length()-2 <= babbling[i].length()){
                if(babbling[i][0]=='a' && babbling[i][1]=='y' && babbling[i][2]=='a' ){
                    babbling[i] = babbling[i].substr(3);
                }
                if(babbling[i][0]=='w' && babbling[i][1]=='o' && babbling[i][2]=='o' ){
                    babbling[i] = babbling[i].substr(3);
                }
            }
            if(babbling[i].length()-1 <= babbling[i].length()){
                if(babbling[i][0]=='y' && babbling[i][1]=='e'){
                    babbling[i] = babbling[i].substr(2);
                }
                if(babbling[i][0]=='m' && babbling[i][1]=='a'){
                    babbling[i] = babbling[i].substr(2);
                }
            }
            if(origin == babbling[i]) { // 위의 if문을 거치고도 현재 문자열이 origin과 같다 => 발음할수있는 경우의수가 존재하지 않는다
                if(i < babbling[i].length()-1) origin = babbling[++i];
                else break;;
            }
            else origin = babbling[i];
        }
        if(babbling[i]=="") answer++;
    }
    
    return answer;
}

int main(){
    vector<string> babbling;
    babbling = {"aya", "yee", "u", "maa", "wyeoo"};
    solution(babbling);
    return 0;
}