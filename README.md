# Baekjoon
✳ Baekjoon coding test   
📍 푸는 과정에서 모르는 것들을 알아가고 메모합니다   
❌ 웬만해서는 폴더경로 및 이름 번경을 하지 않습니다...제발😓

<H3> 목차 </H3>

* [P.for/while](#-pforwhile)
* [P.funciton](#-pfunction)
* [P.sort](#-psort)
* [P.stack](#-pstack)
* [P.Bronze](#-pbronze)
* [P.Silver](#-psilver)
* * *

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
***
<H4>🔗 P.function</H4>

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
***
<H4>🔗 P.sort</H4>

[10814. 나이순정렬](https://www.acmicpc.net/problem/10814)   
🔆 `stable_sort` : 정렬의 비교함수에서 대소관계를 비교할 때 조건이 같다면, 정렬되는 인자를 들어온 순서대로 '안정적'으로 정렬되게 해주는 정렬 함수
- 말 그대로 ! 안정적인 정렬
- 그냥 `sort`보다 빠름 : 그냥 sort는 조건이 같은 것도 정렬과정을 거치기에 수행을 더 많이한다.
***
<H4>🔗 P.stack</H4>

[4949. 균형잡힌 세상](https://www.acmicpc.net/problem/4949)   
🔆 여러줄을 받을 수 있는 함수 <-> `std::cin` : 공백 기준 문자처리
- getline(입력스트림,string 변수, 중단문자) in `<string>` : `char*` 스타일의 문자열을 받아주면 안된다.   

```c++
#include <string>

    string world;
    getline(cin, world);
```

- cin.getline(string 변수,NULL을 포함한 최대 문자 개수, 중단문자) in `<istream>` 
```c++
#include <iostream>

    char world[100];
    int n=10;
    cin.getline(world,n);
```
🆘 조심   
    : `cin`과 `getline`을 연속해서 사용할 경우, `cin.ignore()`을 실행해 버퍼를 비워준 후,    
    사용해야 개행문자 입력구분을 받지 않고 내가 원하는 문자열을 입력할 수 있음!

***
<H4>🔗 P.Bronze</H4>

[1264. 모음의 개수](https://www.acmicpc.net/problem/1264)     
🔆 [대문자를 소문자]로, [소문자를 대문자]로 바꿔주는 라이브러리 `<cctype>` 속의 함수 : `ASCII CODE`적으로 숫자를 대치해서 바꿔주는 것이기 때문에 int를 반환한다 ( `A` : 65 ↔️ `a` : 97 ) 

🆘 조심   
: `reverse` 처럼 반환값없이(void) 스스로 바뀌는 함수가 아니기때문에 반환값을 해당 문자(char)에 재대입해줘야 함을 잊지말자!
```c++
// 정의
tolower(int _c) {
        return (__tolower(_c));
}

toupper(int _c) {
        return (__toupper(_c));
}
// 구현
    char str[256];
    str[i]=tolower(str[i]);
```

***
<H4>🔗 P.Silver</H4>

[11723. 모음의 개수](https://www.acmicpc.net/problem/11723)     
🔆 `memset` = memory + setting, 메모리의 내용을 원하는 크기 만큼 특정값으로 세팅해주는 `<cstring>` 속의 함수   
🆘 조심  
: 특정 세팅값을 `1byte(char) 단위`로 초기화 = int형이나 float형등으로는 원하는 값을 제대로 표현할 수 없음    
➡️ `true`, `false`, `문자`로 초기화한다면 해당 함수는 유용하게 사용가능

```c++
#include <cstring>
int set[10];
memset(set, false, 10);
// 1) 시작주소 2) 세팅값 3) 세팅 길이
```