#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

long long answer = -1;
unordered_map<char, bool> operandLists;

long long Cal(int* idx, string exp, bool flag) {
    if (flag) *idx = *idx + 1;
    string numStr = "";
    if (exp[*idx] == '-') {
        numStr += '-';
        *idx = *idx + 1;
    }
    while (exp[*idx] >= '0' && exp[*idx] <= '9') {
        numStr += exp[*idx];
        *idx = *idx + 1;
    }
    return stoll(numStr);
}

long long CalExp(string exp, char targetOperand) {
    stack<long long> nums;
    stack<char> operands;

    for (int i = 0; i < exp.length(); i++) {
        if (exp[i] == targetOperand) {
            long long num = nums.top(); nums.pop();
            if (exp[i] == '+') {
                num += Cal(&i, exp, true);
            }
            else if (exp[i] == '-') {
                num -= Cal(&i, exp, true);
            }
            else if (exp[i] == '*') {
                num *= Cal(&i, exp, true);
            }
            i--;
            nums.push(num);
        }
        else if ((exp[i] > '9' || exp[i] < '0') && i != 0 && exp[i - 1] >= '0' && exp[i - 1] <= '9') {
            operands.push(exp[i]);
        }
        else {
            nums.push(Cal(&i, exp, false));
            i--;
        }
    }
    return nums.top();
}

string CalExpStr(string exp, char targetOperand) {
    stack<long long> nums;
    stack<char> operands;

    for (int i = 0; i < exp.length(); i++) {
        if (exp[i] == targetOperand) {
            long long num = nums.top(); nums.pop();
            if (exp[i] == '+') {
                num += Cal(&i, exp, true);
            }
            else if (exp[i] == '-') {
                num -= Cal(&i, exp, true);
            }
            else if (exp[i] == '*') {
                num *= Cal(&i, exp, true);
            }
            i--;
            nums.push(num);
        }
        else if ((exp[i] > '9' || exp[i] < '0') && i != 0 && exp[i - 1] >= '0' && exp[i - 1] <= '9') {
            operands.push(exp[i]);
        }
        else {
            nums.push(Cal(&i, exp, false));
            i--;
        }
    }

    string answer = "";
    while (!nums.empty()) {
        if (nums.size() == 1) {
            answer = to_string(nums.top()) + answer;
            break;
        }
        answer = operands.top() + to_string(nums.top()) + answer;
        nums.pop(); operands.pop();
    }
    return answer;
}

void DFS(char operand, string exp, int cnt) {
    if (cnt == operandLists.size()) {
        long long curResult = abs(CalExp(exp, operand));
        if (curResult > answer) answer = curResult;
        return;
    }

    operandLists[operand] = true;   //현재 타겟 연산자에 대한 연산 진행
    exp = CalExpStr(exp, operand);
    for (auto operand = operandLists.begin(); operand != operandLists.end(); operand++) {
        if (!operand->second) {
            DFS(operand->first, exp, cnt + 1);
        }
    }
    operandLists[operand] = false;
}
long long solution(string expression) {
    for (int i = 0; i < expression.length(); i++) {
    if (expression[i] > '9' || expression[i] < '0') {	// 숫자가 아닌 수식 = 연산자
        if (operandLists.find(expression[i]) == operandLists.end()) {
            operandLists[expression[i]] = false;
        }
    }
}

for (auto operand = operandLists.begin(); operand != operandLists.end(); operand++) {
    DFS(operand->first, expression, 1);
}
    return answer;
}