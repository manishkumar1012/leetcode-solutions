class Solution {
public:
    bool isPossible(vector<int>& target) {
        if (target.size() == 1)
            return target[0] == 1;
        
        priority_queue<long> pq;
        long sum = 0;
        for (auto val : target) {
        	sum += val;
        	pq.push(val);
        }
        
        if (pq.top() == sum)
            return false;

        while (pq.top() != 1) {
        	long curr = pq.top();
        	pq.pop();
            
            if (sum - curr == 1)
                return true;
            
            int remSum = sum - curr;
            int diff = curr - remSum;
        	if (diff % remSum <= 0)
                return false;

        	pq.push(diff % remSum);
        	sum += diff % remSum - curr;
        }
        return true;
    }
};
