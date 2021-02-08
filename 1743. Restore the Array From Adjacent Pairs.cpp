// Problem link: https://leetcode.com/contest/weekly-contest-226/problems/restore-the-array-from-adjacent-pairs/

class Solution {
public:
	void dfs(int curr, unordered_map<int, vector<int> >& graph, vector<int>& res, unordered_map<int, int>& vis) {
		vis[curr] = 1;
		res.push_back(curr);
		for (auto next : graph[curr]) {
			if (vis[next])
				continue;
			dfs(next, graph, res, vis);
		}
	}
	vector<int> restoreArray(vector<vector<int>>& adjPairs) {
		int n = adjPairs.size();
		unordered_map<int, vector<int> > graph;
		unordered_map<int, int> vis, deg;
		for (auto v : adjPairs) {
			graph[v[0]].push_back(v[1]);
			graph[v[1]].push_back(v[0]);
			deg[v[0]]++;
			deg[v[1]]++;
		}
		int start = 1;
		for (auto it : deg) {
			if (it.second == 1) {
				start = it.first;
				break;
			}
		}
		vector<int> res;
		dfs(start, graph, res, vis);
		return res;
	}
};