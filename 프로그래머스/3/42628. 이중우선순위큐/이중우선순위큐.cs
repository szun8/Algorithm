using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    public int[] solution(string[] operations) {
        int[] answer = new int[] {0,0};
        List<int> arr = new List<int>();
        
        foreach(string operation in operations){
            if(operation[0] == 'I'){
                int num = int.Parse(operation.Substring(2));
                arr.Add(num);
                arr.Sort();
            }
            else{
                if(arr.Count == 0) continue;
                else if(int.Parse(operation.Substring(2)) == 1){
                    arr.Remove(arr.Max());
                }else{
                    arr.Remove(arr.Min());
                }
            }
        }
        
        if(arr.Count > 0){
            answer[0] = arr.Max();
            answer[1] = arr.Min();
        }
        return answer;
    }
}