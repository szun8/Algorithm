using System;
using System.Collections.Generic;

public class Solution {
    public int solution(string[,] clothes) {
        int answer = 1;
        Dictionary<string, int> types = new Dictionary<string, int>();
        for(int i=0; i<clothes.GetLength(0); i++){
            if(!types.TryAdd(clothes[i,1], 1)){
                types[clothes[i,1]]++;
            }
        }
        
        foreach(int value in types.Values){
            answer *= (value+1);
        }
        return answer-1;
    }
}