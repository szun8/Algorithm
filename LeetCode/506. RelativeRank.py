class Solution:
    def findRelativeRanks(self, score: List[int]) -> List[str]:
        rankHash = dict()
        for i in range(len(score)):
            rankHash[score[i]] = i

        rankHash = sorted(rankHash.items(), reverse=True)
        answer = [-1 for i in range(len(score))]
        for i in range(len(rankHash)):
            
            if(i is 0):
                 answer[rankHash[i][1]] = "Gold Medal"
            elif(i is 1):
                 answer[rankHash[i][1]] = "Silver Medal"
            elif(i is 2):
                 answer[rankHash[i][1]] = "Bronze Medal"
            else:
                 answer[rankHash[i][1]] = str(i+1)
        return answer

        