using System;
using System.Collections.Generic;

public class Solution
{
    public int solution(int n, int[,] results)
    {
        int answer = 0;
        List<int>[] graph = new List<int>[n + 1];
        for (int i = 1; i < n + 1; i++)
        {  // 자료구조 생성
            graph[i] = new List<int>();
            for (int j = 0; j < n + 1; j++)
                graph[i].Add(0);
        }
        for (int i = 0; i < results.GetLength(0); i++)
        {  // 심판의 경기 결과 갱신
            graph[results[i, 0]][results[i, 1]] = 1;
            graph[results[i, 1]][results[i, 0]] = -1;
        }

        // 플로이드 와샬 : 모든 점의 경우의 수를 순회하여 결과를 저장한다
        for (int k = 1; k <= n; k++)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (graph[i][j] != 0) continue; // 이미 승부가 난 조합은 pass
                    if (graph[i][k] == 1 && graph[k][j] == 1) // i가 j를 이긴 경우
                        graph[i][j] = 1;
                    else if (graph[i][k] == -1 && graph[k][j] == -1) // i가 j에게 진 경우
                        graph[i][j] = -1;
                }
            }
        }

        for (int i = 1; i < n + 1; i++)
        {   // 각 선수(행)의 승부 조합이 모두 채워져있다면 순위를 메길수 있음.
            bool isOk = true;
            for (int j = 1; j <= n; j++)
            {
                if (i == j) continue;
                if (graph[i][j] == 0)
                {   // 하나라도 0으로 승부의 결과가 없다면 순위 카운팅 불가.
                    isOk = false;
                    break;
                }
            }
            if (isOk) answer++;
        }
        return answer;
    }
}