/*
	2 5 1 5 6 2
    For O(n) space, it is easy to do by precomputing leftMax and rightMax.
    For O(1) space: 
    At any index, leftMax can be used to calculate the result only if there is something larger than leftMax in the right.
    So we take two pointers left and right. We move the left pointer only if there is something larger in the right.
    This way, we can be sure that leftMax is smaller than rightMax and it can be used to calculate the answer for that index.
    Similarly, if right value is smaller than left, we move the right pointer.
    In one line, if we reached at an index with left pointer, either that is the leftMax or leftMax is minimum for that index and same goes for the right.

*/

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        int res = 0;
        while (left <= right) {
        	if (height[left] <= height[right]) {
        		if (height[left] < leftMax)
        			res += leftMax - height[left];
        		else
        			leftMax = height[left];
                left++;
        	} else {
        		if (height[right] < rightMax)
        			res += rightMax - height[right];
        		else
        			rightMax = height[right];
                right--;
        	}
        }
        return res;
    }
};
