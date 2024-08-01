from functools import cmp_to_key

def solution(numbers):
    if(numbers.count(0) == len(numbers)):
        return "0"

    answer = ''
    str_numbers = []
    for element in numbers:
        str_numbers.append(str(element))
    
    str_numbers.sort(key=cmp_to_key(compareTo))

    for element in str_numbers:
        answer+=element

    return answer

def compareTo(num1, num2):
    if(len(num1) > len(num2)):
        for i in range(len(num2)):
            if(num1[i] == num2[i]): continue
            else: 
                if(num1[i]>num2[i]): return -1
                else: return 1
    else:
        for i in range(len(num1)):
            if(num1[i] == num2[i]): continue
            else: 
                if(num1[i]>num2[i]): return -1
                else: return 1

    # 작은 수 기준으로 모든 자릿수가 동일할 경우,
    a = int(num1+num2)
    b = int(num2+num1)
    if(a > b): return -1
    else: return 1