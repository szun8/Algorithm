from collections import deque

def solution(queue1, queue2):
    que1Sum = sum(queue1)
    que2Sum = sum(queue2)

    totalSum = que1Sum + que2Sum
    if (totalSum % 2 == 1):
        return -1
    else:
        needNum = int(totalSum / 2)

    # 더 큰 sum 가려내기
    if(que1Sum > que2Sum):
        moreSum = que1Sum
        moreQue = deque(queue1)
        lessQue = deque(queue2)
    else:
        moreSum = que2Sum
        moreQue = deque(queue2)
        lessQue = deque(queue1)

    diffSum = moreSum - needNum
    maxCnt = len(queue1) * 2 +1

    cnt = 0
    while(diffSum != 0):
        if(cnt > maxCnt):
            cnt = -1
            break

        if(diffSum > 0):
            tmp = moreQue.popleft()
            cnt += 1
            lessQue.append(tmp)
            diffSum -= tmp

        elif(diffSum < 0):
            tmp = lessQue.popleft()
            cnt += 1
            moreQue.append(tmp)
            diffSum += tmp
        
    return cnt