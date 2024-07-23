import math

def solution(arrayA, arrayB):
    answer = 0
    arrayA.sort()
    arrayB.sort()
    
    maxA = GetmaxN(arrayA)
    maxB = GetmaxN(arrayB)

    isModA = GetmodFalse(maxA, arrayB)
    isModB = GetmodFalse(maxB, arrayA)

    if(isModA and isModB):
        return max(maxA, maxB)
    elif(isModA):
        return maxA
    elif(isModB):
        return maxB
    return answer

def GetmaxN(array):
    sqrt = int(math.sqrt(array[0]))
    divisor = [array[0]]
    for i in range(2, sqrt+1):
        if(array[0]%i == 0):
            divisor.append(i)
            divisor.append(array[0]//i)
    divisor.sort()
    
    max = -1
    while divisor:
        isMod = True
        for i in range(1, len(array)):
            if(array[i] % divisor[-1] != 0):
                divisor.pop()
                isMod = False
                break
        if(isMod):
            max = divisor[-1]
            break
    return max

def GetmodFalse(max, array):
    if(max < 0): return False
    for i in range(len(array)):
        if(array[i] % max == 0): #하나라도 나눠떨어지면 실패
            return False
    return True