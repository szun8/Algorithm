#include <queue>
#include <iostream>

#define MAX 1000000000

struct Node{
public:
    long long num;
    int cnt;
public:
    Node(long long a, int b) : num(a), cnt(b){};
};
// 1000000000
// 430000000 503270511
int BFS(int src, int target){
    int answer = -1;
    std::queue<Node> number;
    number.push(Node(src, 0));

    while(!number.empty()){
        Node curNum = number.front();
        number.pop();
        if(curNum.num > MAX) break;
        else if(curNum.num > target) continue;
        else if(curNum.num == target) {
            answer = curNum.cnt;
            break;
        }

        if(curNum.num*2 > MAX) continue;
        number.push(Node(curNum.num*2, curNum.cnt+1));      // *2 

        if(curNum.num*10+1 > MAX) continue;     // 피연산자의 자료형을 기준으로 연산을 진행해야한다. 그래야 오버플로우가 발생하지 않음
        number.push(Node(curNum.num*10+1, curNum.cnt+1));   // *10 + 1
    }
    if(answer > -1) return answer+1;
    else return -1;
}

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d",BFS(a, b));
    return 0;
}
