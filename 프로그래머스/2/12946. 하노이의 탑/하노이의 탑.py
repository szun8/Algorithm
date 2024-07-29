answer = []
def solution(n):
    GetHanoi(n, 1, 2, 3)
    return answer

def GetHanoi(n, start, assist, dest):
    if(n == 1):
        answer.append([start, dest])
        return
    
    GetHanoi(n-1, start, dest, assist)
    answer.append([start, dest])
    GetHanoi(n-1, assist, start, dest)
    return
        