using System;

public class Solution {
    public long solution(int n, int[] times) {
        long left = times[0];
        long right = times[times.Length-1]*(long)n;
        
        while(left<=right){
            long mid = (left+right)/2;
            
            long cnt = 0;
            for(int i=0; i<times.Length; i++){
                cnt += (mid/times[i]);
                if(cnt >= n) break;
            }
            
            if(cnt >= n) right = mid-1;
            else left = mid +1;
        }
        return left;
    }
}