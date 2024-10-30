using System;
using System.Collections.Generic;

public class Solution {
    public int[] solution(int[] prices)
{
    int[] answer = new int[prices.Length];
    Queue<int> q = new Queue<int>(prices);

    for (int i = 0; i < prices.Length; i++)
    {
        int time = 0;
        int comp = q.Dequeue();

        for (int j = i + 1; j < prices.Length; j++)
        {
            time++;
            if (comp > prices[j] || j == prices.Length - 1)
            {
                answer[i] = time;
                break;
            }
        }
    }
    return answer;
}
}