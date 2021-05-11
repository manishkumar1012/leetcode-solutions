class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
    	int n = cardPoints.size();
        int prefSum[100001] = {0};
        prefSum[1] = cardPoints[0];

        for (int i = 1; i < n; i++) {
        	prefSum[i + 1] = prefSum[i] + cardPoints[i];
        }

        int maxmScore = 0;
        for (int i = 0; i <= k; i++) {
        	int leftSum = prefSum[i];
        	int rightSum = prefSum[n] - prefSum[n - (k - i)]; 

        	maxmScore = max(maxmScore, leftSum + rightSum);
        }
        return maxmScore;
    }
};
