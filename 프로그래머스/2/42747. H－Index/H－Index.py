def solution(citations):
    answer = 0
    citations.sort() #오름차순 #nlogn
    length = len(citations)

    for h in range(length+1):   #n^2
        i = 0
        while i < length:
            if(citations[i] >= h and length-i >= h):
                if(i>0 and i-1 <= h):
                    answer = h
                    break
                elif i is 0:
                    answer = h
                    break
            i += 1

    return answer