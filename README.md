# Baekjoon
✳ Baekjoon coding test   
📍 푸는 과정에서 모르는 것들을 알아가고 메모합니다   
❌ 웬만해서는 폴더경로 및 이름 번경을 하지 않습니다...제발😓

<H4>🔗 P.for/while</H4>
- cin/cout 최적화 in 빠른 A+B   

```c++
    // 선언
    cin.tie(NULL);

    ios_base::sync_with_stdio(false);
    // iostream 동기화 비활성화 처리로 딜레이(시간사용) 방지
    // 대신 C 언어의 문법인 printf/scanf/put 등의 사용 X
    // 싱글쓰레드에서 사용시 출력 순서 문제 없음
    // 멀티쓰레드에서 사용시 문제 발생 가능

    // endl => "\n" 사용
```
<H4>🔗 P.funciton</H4>

[15596. 정수 N개의 합](https://www.acmicpc.net/problem/15596)
```c++
#include <vector>
#include <numeric>
long long sum(std::vector<int> &a) {
	long long ans = 0;
	return ans = accumulate(a.begin(),a.end(),0LL);
}
```
 - accumulate(시작, 끝, 초기값) 함수 : 지정된 범위안의 수를 더해주는 함수, 초기값은 적어주는대로 반환 타입이 정해짐 -> `0`을 입력하면 자동 `int`로 캐스팅, 그러므로 다른 자료형으로 반환하고자 할 때는 그에 맞게 초기값 설정을 해야 에러가 나질 않음!😅   
  // `long long` : `0LL` 
    