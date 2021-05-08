class Solution {
public:
    int minOperations(vector<int>& nums) {
        int res = 0;
        for (int i = 1; i < nums.size(); i++) {
            res += max(nums[i - 1] - nums[i] + 1, 0);
            nums[i] = max(nums[i - 1] + 1, nums[i]);
        }
        return res;
    }
};
