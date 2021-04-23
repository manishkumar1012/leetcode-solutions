// Problem Link: https://leetcode.com/problems/ways-to-make-a-fair-array/

class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        vector<int> oddSum(n), evenSum(n);
        oddSum[0] = 0;
        evenSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
        	oddSum[i] = oddSum[i - 1];
        	evenSum[i] = evenSum[i - 1];
        	if (i & 1) 
        		oddSum[i] += nums[i];
        	else
        		evenSum[i] += nums[i]; 
        }
        
        int res = 0;
        for (int i = 0; i < n; i++) {
        	int oddTotal, evenTotal;
            if (!i) {
            	oddTotal = evenSum[n - 1] - evenSum[i];
				evenTotal = oddSum[n - 1] - oddSum[i]; 
            } else {
	    		oddTotal = oddSum[i - 1] + evenSum[n - 1] - evenSum[i];
				evenTotal = evenSum[i - 1] + oddSum[n - 1] - oddSum[i]; 
			}
			if (oddTotal == evenTotal)
				res++;       
        }
        
        return res;
    }
};
