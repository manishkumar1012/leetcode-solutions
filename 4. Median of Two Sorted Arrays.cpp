// Problem Link: https://leetcode.com/problems/median-of-two-sorted-arrays/
// Video Solution: https://www.youtube.com/watch?v=ws98ud9uxl4

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if (m > n)
        	return findMedianSortedArrays(nums2, nums1);

        int begin1 = 0, end1 = m;
        while (begin1 <= end1) {
        	int count1 = (begin1 + end1) / 2;
        	int count2 = (m + n + 1) / 2 - count1;

        	int min1 = (count1 == m) ? INT_MAX : nums1[count1];
        	int max1 = (!count1) ? INT_MIN : nums1[count1 -  1];

        	int min2 = (count2 == n) ? INT_MAX : nums2[count2];
        	int max2 = (!count2) ? INT_MIN : nums2[count2 -  1];

        	if (max1 <= min2 && max2 <= min1) {
        		if ((m + n) & 1) 
        			return (double)(max(max1, max2));
        		else 
        			return (double)((max(max1, max2) + min(min1, min2)) / 2.0);
        	} else if (max1 < min2) {
        		begin1 = count1 + 1;
        	} else {
        		end1 = count1 - 1;
        	}
        }
        return 0;
    }
};
