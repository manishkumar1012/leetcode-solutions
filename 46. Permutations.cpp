class Solution {
public:
    void getAllPermutation(int pos, vector<int>& nums, vector<vector<int>>& res) {
        if (pos == nums.size() - 1) {
            res.push_back(nums);
            return;
        }
        for (int i = pos; i < nums.size(); i++) {
            swap(nums[i], nums[pos]);
            getAllPermutation(pos + 1, nums, res);
            swap(nums[i], nums[pos]);
        }
        return;
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        getAllPermutation(0, nums, res);
        return res;
    }
};

/*
    [1, 2, 3]
    recur
    1 _ _  we are left with [2, 3] unused
    1 2 _  we are left with [3] unused
    1 2 3
    backtrack
    1 2 _
    3 is already processed
    1 _ _
    [2, 3] earlier we had chosen 2, so now we can choose 3
    1 3 _
    1 3 2
    backtrack again
    .
    .
    .
    
    We are swapping because we need to maintain the used and unused elements.
    So the left part is used and right part has unused elements.
    
    We need second swap because we are iterating on the elements by order.
    If we do not use that then the output for [1, 2, 3 ] will be
        [[1,2,3],[1,3,2],[3,1,2],[3,2,1],[1,2,3],[1,3,2]] which is incorrect (5th permutation).
*/
