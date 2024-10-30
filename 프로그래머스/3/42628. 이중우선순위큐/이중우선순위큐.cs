using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    public int[] solution(string[] operations) {
        int[] answer = new int[] {0,0};
        LinkedList<int> arr = new LinkedList<int>();
        
        foreach(string operation in operations){
            if(operation[0] == 'I'){
                int num = int.Parse(operation.Substring(2));
                arr.AddLast(num);
                List<int> tmp = new List<int>(arr);
                tmp.Sort(); // 오름차순
                arr = new LinkedList<int>(tmp);
            }
            else{
                if(arr.Count == 0) continue;
                else if(int.Parse(operation.Substring(2)) == 1){
                    arr.RemoveLast();
                }else{
                    arr.RemoveFirst();
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