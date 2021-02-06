class Solution {
public:
	int countStudents(vector<int>& students, vector<int>& sandwiches) {
		int n = sandwiches.size();
		int cntZero = 0, cntOne = 0;
		for (auto val : students) {
			if (val)
				cntOne++;
			else
				cntZero++;
		}
		for (int i = 0; i < n; i++) {
			int currVal = sandwiches[i];
			if (currVal) {
				if (!cntOne)
					return n - i;
				cntOne--;
			}
			else {
				if (!cntZero)
					return n - i;
				cntZero--;
			}
		}
		return 0;
	}
};