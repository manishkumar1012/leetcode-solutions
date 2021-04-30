// Problem link: https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution {
public:
	unordered_map<char, string > digitToChars = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

	void buildCombinations(int ind, string str, vector<string>& res, string &digits) {
		if (ind == digits.length()) {
			res.push_back(str);
			return;
		}

		string curr = digitToChars[digits[ind]];
		for (auto ch : curr) {
			buildCombinations(ind + 1, str + ch, res, digits);
		}
	}

    vector<string> letterCombinations(string digits) {
    	vector<string> res;
    	if (!digits.length())
    		return res;

        buildCombinations(0, "", res, digits);
        return res;
    }
};
