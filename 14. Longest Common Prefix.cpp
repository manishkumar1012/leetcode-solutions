// Problem link: https://leetcode.com/problems/longest-common-prefix/
// Idea: The code below is very much self explanatory.
    // We first sort the array of strings.
    // Then, we choose the first and last string in the array. [They are supposed to be the most different among all the pairs of strings in the sorted array]
    // We just compare how many common characters match from index i = 0 of these two strings.

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
