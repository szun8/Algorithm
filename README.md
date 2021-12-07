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

[10816. 숫자 카드2](https://www.acmicpc.net/problem/10816)     
🔆 `upper_bound` = 배열 속에서 찾으려는 key값보다 처음으로 `초과`하는 숫자의 위치를 찾아서 반환해주는 함수   
🔆 `lower_bound` = 배열 속에서 찾으려는 key값과 같거나 큰 숫자의 위치를 찾아서 반환해주는 함수   
🆘 조심  
: 오름차순으로 `정렬된 배열`에서 사용해야하며 `마지막 인덱스값`을 가지고 싶을 경우를 대비해 배열의 크기를 원하는 크기`+1`를 해주고 해당 인덱스에 제일 큰 값을 지정해줘야 정렬 후 함수 사용시, 제대로 된 인덱스 값을 추출할 수 있음

```c++
#include <algorithm>
#include <vector>

vector<int> bound;  // start = 3 -1 5 2
bound.push_back(3);
bound.push_back(-1);
bound.push_back(5);
bound.push_back(2);

sort(bound.begin(),bound.end()); // 오름차순 = -1 2 3 5

cout << upper_bound(2)-bound.begin() << endl; // index 2 반환
cout << lower_bound(2)-bound.begin() << endl; // index 1 반환
```

[11004. K번째 수](https://www.acmicpc.net/problem/11004)     
🔆 `nth_element` = n번째 수가 정렬될 때까지만 정렬해주는 `<algorithm>` 속의 부분 정렬 함수   
🆘 조심  
: n번째가 마지막 번째의 수가 아니라면 전체정렬을 하는 `sort`보다 시간복잡도를 (비교적)줄여줌, 기본적으로 `오름차순`, 마지막에 `비교함수`를 통해 원하는 조건 정렬도 가능

```c++
#include <algorithm>
#include <vector>

vector<int> elementSort;    // start = 3 -1 5 2
elementSort.push_back(3);
elementSort.push_back(-1);
elementSort.push_back(5);
elementSort.push_back(2);

nth_element(elementSort.begin(), elementSort.begin()+2,elementSort.end()); // index 2번이 자리할 때까지 정렬
nth_element(elementSort.begin(), elementSort.begin()+ elementSort.size()/2, elementSort.end()); // 중간값
```

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

___
<H6>보고 잘못되거나 이상한 부분은 comment 남겨주세요 😂</H6>