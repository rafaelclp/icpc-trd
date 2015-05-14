// Unsorted output; doesn't include duplicated points.
// Running time: O(V+E)

vector<int> G[MAXN];
int idx[MAXN], times; bool vis[MAXN], isAns[MAXN]; vector<int> ans;
#define ROOT 0 // any vertice in the graph to call getArticulationPoints with
int getArticulationPoints(int v=ROOT) {
	vis[v] = true, idx[v] = times++;
	int children = 0, lowest = idx[v];
	for (int i = 0; i < (int)G[v].size(); i++) {
		if (!vis[G[v][i]]) {
			int m = getArticulationPoints(G[v][i]);
			lowest = min(lowest, m), children++;
			if (idx[v] <= m && (v != ROOT || children >= 2) && !isAns[v])
				isAns[v] = true, ans.push_back(v);
		} else lowest = min(lowest, idx[G[v][i]]);
	}
	return lowest;
}
