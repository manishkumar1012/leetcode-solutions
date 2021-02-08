class Solution {
public:
	double averageWaitingTime(vector<vector<int>>& customers) {
		int lastFinishTime = 0;
		double waitingTime = 0;
		for (auto customer : customers) {
			int arrivalTime = customer[0];
			int cookingTime = customer[1];
			if (lastFinishTime < arrivalTime)
				lastFinishTime = arrivalTime;
			int currFinishTime = lastFinishTime + cookingTime;
			waitingTime += currFinishTime - arrivalTime;
			lastFinishTime = currFinishTime;
		}
		double avgWaitingTime = (waitingTime) / (customers.size() * 1.0);
		return avgWaitingTime;
	}
};