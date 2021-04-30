class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int cnt = 0;
        int lastInd = 0;
        for (int i = 0; i < s1.length(); i++) {
        	if (s1[i] != s2[i]) {
        		cnt++;
        		if (cnt > 2)
        			return false;
        		else if (cnt == 2) 
        			swap(s1[lastInd], s1[i]);
        		else
        			lastInd = i;
        	}
        }

        return s1 == s2;
    }
};
