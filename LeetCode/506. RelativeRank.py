class Solution:
    def findRelativeRanks(self, score: List[int]) -> List[str]:
        sortedScores = sorted(score, reverse = True)
        d = {sortedScores[i]: i+1 for i in range(len(sortedScores))}

        res = []
        for i, val in enumerate(score):
            if d[val] == 1: res.append("Gold Medal")
            elif d[val] == 2: res.append("Silver Medal")
            elif d[val] == 3: res.append("Bronze Medal")
            else: res.append(f"{d[val]}")
        return res