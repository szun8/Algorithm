import heapq

def solution(scoville, K):
    answer = 0
    heapq.heapify(scoville)
    # 원하는 K가 되지 않는 경우를 처리해줘야한다
    while(scoville[0] < K):
        if(len(scoville) == 1): return -1
        minEle1 = heapq.heappop(scoville)
        minEle2 = heapq.heappop(scoville) * 2
        newEle = minEle1 + minEle2
        heapq.heappush(scoville, newEle)
        answer += 1
    return answer