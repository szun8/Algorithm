#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    long long nump = stoll(p);  
    // 문자열의 크기가 10,000이므로 숫자 변환 시, int 자료형 크기를 넘는다 => core dumped 원인
    // 따라서 long long으로 바꿔주거나 문자끼리 비교하는 방식을 채택하는 것이 해결방법

    for(int i=0; i<=(t.length()-p.length());i++){
        string tmpNum = t.substr(i, p.length());
        long long num = stoll(tmpNum);
        if(num <= nump) ++answer;
    }
    return answer;
}

int main(){
    solution("3141592", "271");
    return 0;
}