from collections import deque

def solution(cards1, cards2, goal):
    answer = 'Yes'
    Qcard1 = deque(cards1)
    Qcard2 = deque(cards2)
    
    for element in goal:
        if len(Qcard1) > 0 and Qcard1[0] == element:
            Qcard1.popleft()
        elif len(Qcard2) > 0 and Qcard2[0] == element:
            Qcard2.popleft()
        else:
            return 'No'
        
    return answer