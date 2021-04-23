// Problem link: https://leetcode.com/problems/course-schedule-ii/

class Solution {
public:
	bool isCyclic(int u, vector<vector<int> > &graph, vector<int> &vis) {
		vis[u] = 1;
		for (auto v : graph[u]) {
			if (vis[v] == 1)
				return true;
			else if (vis[v] == 2)
				continue;
			else {
				if (isCyclic(v, graph, vis))
                    return true;
            }
		}
		vis[u] = 2;
		return false;
	}

	void dfs(int u, vector<vector<int> > &graph, vector<int> &vis, vector<int> &res) {
		vis[u] = 1;
		for (auto v : graph[u]) {
			if (!vis[v])
				dfs(v, graph, vis, res);
		}
		res.push_back(u);
	}

    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        vector<vector<int> > graph(numCourses + 1);
        for (auto v : pre) {
        	graph[v[1]].push_back(v[0]);
        }
        vector<int> vis(numCourses + 1, 0);
        vector<int> res;
        for (int i = 0; i < numCourses; i++) {
        	if (!vis[i]) {
                if (isCyclic(i, graph, vis))
        		    return res;
            }
        }
        fill(vis.begin(), vis.end(), 0);
        for (int i = 0; i < numCourses; i++) {
        	if (!vis[i]) 
        		dfs(i, graph, vis, res);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
