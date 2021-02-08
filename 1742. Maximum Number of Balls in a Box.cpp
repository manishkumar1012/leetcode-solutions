// Problem link: https://leetcode.com/contest/weekly-contest-226/problems/maximum-number-of-balls-in-a-box/

class Solution {
public:
    int countBalls(int low, int high) {
        unordered_map<int, int> cnt;
        int ans = 0;
        for (int i = low; i <= high; i++) {
            int temp = i;
            int sum = 0;
            while (temp) {
                sum += temp % 10;
                temp = temp / 10;
            }
            cnt[sum]++;
            if (cnt[sum] > ans)
                ans = cnt[sum];
        }
        return ans;
    }
};