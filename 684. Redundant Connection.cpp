// Problem Link: https://leetcode.com/problems/redundant-connection/

class Solution {
public:
	vector<int> par;

	int findRoot(int v) {
		if (par[v] == v)
			return v;
		return findRoot(par[v]);
	}

	void unionRoots(int u, int v) {
		par[u] = v;
	}

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        par.resize(edges.size() + 1);
        for (int i = 1; i < par.size(); i++) {
            par[i] = i;
        }
        vector<int> res;
        for (auto edge : edges) {
        	int u = edge[0];
        	int v = edge[1];
        	if (findRoot(u) == findRoot(v))
        		res = edge;
        	unionRoots(findRoot(u), findRoot(v));
        }
        return res;
    }
};
