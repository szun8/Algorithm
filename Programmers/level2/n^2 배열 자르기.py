def solution(n, left, right):
    arr = []
    if(int(left/n) == int(right/n)):
        for j in range(left%n, right%n+1): 
                if(int(left/n) >= j):
                    arr.append(int(left/n)+1)
                else:
                    arr.append(j+1)

    else:
        for i in range(int(left/n), int(right/n+1)):
            if(i == int(left/n)):
                for j in range(left%n, n): 
                    if(i >= j):
                        arr.append(i+1)
                    else:
                        arr.append(j+1)
            elif(i == int(right/n)):
                for j in range(0, right%n+1):  
                    if(i >= j):
                        arr.append(i+1)
                    else:
                        arr.append(j+1)
            else:
                for j in range(n):  # 0~3
                    if(i >= j):
                        arr.append(i+1)
                    else:
                        arr.append(j+1)
    return arr


print(solution(4, 4, 6))