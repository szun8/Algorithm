def solution(numbers):
    answer = [-1] * len(numbers)
    index_stack = []
    for i in range(len(numbers)):
        while index_stack and numbers[index_stack[-1]] < numbers[i] :
            answer[index_stack.pop()] = numbers[i]
        index_stack.append(i)
    return answer