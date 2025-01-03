<H3>목차</H3>

1. [BOJ](#boj)

2. [Programmers](#programmers)

---
 
### BOJ
	
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

[2712. 미국 스타일](https://www.acmicpc.net/problem/2712)     
🔆 c++에서 소수점 나타내기  

🆘 조심   
: 출력되지 않는 뒷부분 자릿수에 대해서는 자동 반올림이 된다!   
만약 반올림을 원하지 않는다면, 이하 숫자를 버리고 출력하기 
```c++
float num = 1234.56789;
// *** 1) 전체 자릿수
cout.precision(5); // 자릿수 고정 함수 = 내가 나타내고 싶은 전체 자릿수, 출력값의 앞부터 카운팅
cout<<num;         // 1234.5

// *** 2) 소수점 자릿수
cout<<fixed;    // 소수점 아랫값을 고정하는 함수
cout.precision(4);
cout<<num;         // 1234.5678
```

[5344. 화성 수학](https://www.acmicpc.net/problem/5355)     
🔆 split해주기 - `stringstream` : 공백기준으로 문자열 자르기 in `<sstream>`   
✏️ `>>` : in / `<<` : out 

```c++
#include <sstream>  // istringstream(>>) + ostringstream(<<) = stringstream
#include <iostream>
using namespace std;

string str // 문자열 입력
string splitWord;  // str에서 파싱된 문자(열) 입력
getline(cin, str);

stringstream splitStr(str);     // 잘라줄 문자열 넣기
while(splitStr >> splitWord){   
// 잘라진 문자(열) 입력 (추출-복사의 과정)
// 더이상 str에 맞는 자료형이 없을 때까지 반복해줌
    cout<<splitWord<<endl;
}
```
🔆 추가로 `substr`을 써도 문자열 자르기가 가능하다! 

[9654. 나부 함대 데이터](https://www.acmicpc.net/problem/9654)     
🔆 원하는 만큼 공백란 출력 : printf("%-숫자s", string);

```c++
#include <iostream>
using namespace std;
printf("%-s5%-s10","Baekjoon","code");
//Baekjoon     code          
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

***
<H4>🔗 P.Gold</H4>

[1707. 이분 그래프](https://www.acmicpc.net/problem/1707)     
🔆 `이분 그래프 Bipartite Graph` : 인접한 정점에 자신과 서로 다른 색을 칠하여 모든 정점이 두가지 색으로 색칠되는 그래프   
모든 정점이 두 그룹으로 나뉘어지고 서로 인접한 정점의 색이 자신과 같으면 이분그래프가 아니다   
➡️ 그래프를 탐색해서 정점을 확인하는 것이기때문에 `DFS/BFS`을 사용  
➡️ BFS탐색시, 같은 레벨의 정점끼리는 모두 같은 색으로 칠해진다   
🆘 조심  
: 모든 상황에서 모든 그래프가 연결되어있는 것이 아니기때문에 비연결 그래프도 확인해줘야한다!

---

### Programmers

>`unique()` in `vector`   
🔗 [두 개 뽑아서 더하기](https://github.com/szun8/Programmers/commit/c46c703f260c13f6746a437fa984fcd553fbff67#r54506994)


> `isDight()` in `string` `cctype`   
 🔗 [문자열 다루기 기본](https://github.com/szun8/Programmers/commit/f7b73a25ff39ea350d27dd39cd8c280933b692f7#r54506830)

> `tolower` `toupper` in `string` `cctype`   
 🔗 [문자열 내 p와 y의 개수](https://github.com/szun8/Programmers/commit/8a2393bcd208b28bcb27df6bc43bfe7af1465deb#r54579595)

> `find()` in `string`  
 🔗 [숫자 문자열과 영단어](https://github.com/szun8/Programmers/commit/dabb4ae965eddbc8fc2376ba5f6f40d53b342d78#r54775165)

> `max_element` `min_element` in `algorithm`  
 🔗 [상호 평가](https://github.com/szun8/Programmers/commit/ff92735e745d59c645de2562b971f36e782c7f79#r55129091)   

> `최대공약수` `최소공배수` by `유클리드 호제법`   
 🔗 [최대공약수와 최소공배수](https://github.com/szun8/Programmers/commit/da1ff0bd0285c7ba8d624cf1bed84a0659a5631d#r55128718)

> `Greedy Algorithm`    
🔗 [체육복](https://github.com/szun8/Programmers/commit/9bf7342cfb6ad79c30b02934398614e472a6ebfa?branch=9bf7342cfb6ad79c30b02934398614e472a6ebfa&diff=unified#r55182498)


> `Map` in `associative container` `c++ study`   
 🔗 [문자열 내 마음대로 정렬하기](https://github.com/szun8/Cpp_Unreal_lec#-map)

> `istringstream` `getline` `lambda`  
 🔗 [4주차-직업군 추천하기](https://github.com/szun8/Programmers/commit/7391518217e329631edafdd06e8d8a149eec221d#r55452700)   

> `에라토스테네스의 체`  
🔗 [소수 찾기](https://github.com/szun8/Programmers/commit/9148a3eafb814b93c0b221214b3ccfe49de2c92d?branch=9148a3eafb814b93c0b221214b3ccfe49de2c92d&diff=unified#r55452119)

