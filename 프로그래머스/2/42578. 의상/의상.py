def solution(clothes):
    answer = 1
    dict = {}
    for cloth, type in clothes:
        if type in dict.keys():
            dict[type] += [cloth]
        else:
            dict[type] = [cloth]
            
    for i, val in dict.items():
        answer *= (len(val)+1)
            
    return answer -1