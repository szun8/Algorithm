import queue, math

def solution(progresses, speeds):
    answer = []
    progressQ = queue.Queue()
    
    for i in range(len(progresses)):
        progressQ.put(int(math.ceil((100 - progresses[i]) / speeds[i])))
        
    while(progressQ.empty() == False):
        cnt = 1
        topProgress = progressQ.get()
        while(progressQ.empty() == False and topProgress >= progressQ.queue[0]):
            cnt += 1
            progressQ.get()
        answer.append(cnt)
        
    return answer