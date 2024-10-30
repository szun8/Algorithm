using System;
using System.Collections.Generic;

public class Solution {
    public int solution(int n, int[,] results) {
         int answer = 0;
         List<int>[] graph = new List<int>[n + 1];
         for (int i = 1; i < n + 1; i++)
         {
             graph[i] = new List<int>();
             for (int j = 0; j < n + 1; j++)
                 graph[i].Add(0);
         }
         for (int i = 0; i < results.GetLength(0); i++)
         {
             graph[results[i, 0]][results[i, 1]] = 1;
             graph[results[i, 1]][results[i, 0]] = -1;
         }

         for (int k = 1; k <= n; k++)
         {
             for (int i = 1; i <= n; i++)
             {
                 for (int j = 1; j <= n; j++)
                 {
                     if (graph[i][j] != 0) continue;
                     if (graph[i][k] == 1 && graph[k][j] == 1)
                         graph[i][j] = 1;
                     else if (graph[i][k] == -1 && graph[k][j] == -1)
                         graph[i][j] = -1;
                 }
             }
         }
        
        for (int i = 1; i < n + 1; i++)
        {
            bool isOk = true;
            for(int j = 1; j <= n; j++)
            {
                if (i == j) continue;
                if (graph[i][j] == 0)
                {
                    isOk = false;
                    break;
                }
            }
            if (isOk) answer++;
        }
        return answer;
    }
}