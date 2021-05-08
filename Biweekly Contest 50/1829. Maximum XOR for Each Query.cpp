/* 
	Idea: To maximize numsArray ^ k, consider all the 0 bits in numsXor and set that in k if possible (k < 2 ^ maximumBit)
		  Increase k even for the bits later than msb. For ex (00010110), set k for last 3 0 bits also.
*/

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        int numsXor = 0;
        for (auto num : nums)
        	numsXor = numsXor ^ num;

        vector<int> res;
        for (int i = n - 1; i >= 0; i--) {
        	int resk = 0;
        	int currXor = numsXor;
        	int cnt = 0;
        	while (resk < (1 << maximumBit)) {
        		int currBit = currXor & 1;
        		if (!currBit) {
        			if ((resk + (1 << cnt)) < (1 << maximumBit)) {
        				resk += 1 << cnt;
        			} else {
        				break;
        			}
        		}
        		currXor = currXor >> 1;
        		cnt++;
        	}

            numsXor = numsXor ^ nums[i];
        	res.push_back(resk);
        }
        return res;
    }
};
