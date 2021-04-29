// Problem link: https://leetcode.com/problems/longest-common-prefix/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i = 0, j = 0;
        string res = "";
        int ind = 0;
        int n = strs.size();
        if (!n)
            return res;
        while (true) {
            if (ind >= strs[0].length())
                return res;
            int currChar = strs[0][ind];
            for (int i = 1; i < n; i++) {
                if (ind >= strs[i].length() || (strs[i][ind] != currChar))
                    return res;
            }
            ind++;
            res += currChar;
        }
        return res;
    }
};
