def solution(citations):
    answer = 0
    citations.sort() #오름차순
    maxCnt = min(len(citations), citations[-1])
    length = len(citations)
    for h in range(maxCnt+1):
        for i in range(length):
            if(citations[i] >= h and length-i >= h):
                if(i>0 and i <= h):
                    answer = h
                    break
                elif i is 0:
                    answer = h
                    break

    return answer