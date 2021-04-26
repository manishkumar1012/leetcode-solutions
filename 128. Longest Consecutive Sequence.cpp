// Problem link: https://leetcode.com/problems/longest-consecutive-sequence/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int ans = 0;
        for (auto num : nums) {
        	if (st.find(num) == st.end())
        		continue; 

        	st.erase(num);
        	int prev = num - 1, next = num + 1;

        	while (st.find(prev) != st.end())
        		st.erase(prev--);

        	while (st.find(next) != st.end())
        		st.erase(next++);
        	ans = max(ans, next - prev - 1);
        }
        return ans;
    }
};
