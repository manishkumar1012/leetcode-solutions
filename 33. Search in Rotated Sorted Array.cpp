/*
	[7 8 19 32 33 55 3 4 5]

	Even if target is less than nums[mid], we can't say that the target lies in left part because of rotaion.
	
	Base case
	if (nums[mid] == target)
		return mid;

	Rotation cases
	Mid lies in the left part
	if (nums[mid] > nums[left]) {
		if (target > nums[left] && target < nums[mid])
			right = mid - 1;
		else
			left = mid + 1; 
	}

	Mid lies in the right part
	else if (nums[mid] < nums[right]) {
		if (target > nums[mid] && target < nums[right]) 
			left = mid + 1;
		else
			right = mid - 1;
	}
    
    No rotation case
	else {
		if (nums[mid] < target)
			left = mid + 1;
		else
			right = mid - 1;
	} 
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
        	int mid = (left + right) / 2;
  			if (nums[mid] == target)
  				return mid;

            if (nums[mid] > nums[right]) {
				if (target >= nums[left] && target < nums[mid])
					right = mid - 1;
				else
					left = mid + 1; 
			} else if (nums[mid] < nums[left]) {
				if (target > nums[mid] && target <= nums[right]) 
					left = mid + 1;
				else
					right = mid - 1;
			} else {
				if (nums[mid] < target)
					left = mid + 1;
				else
					right = mid - 1;
			}
        }
        return -1;
    }
};
