// Calculates the sum of dist(v,u) for all pairs of vertices v, u.
// Running time: O(n)

int distsum, n;
int dfs(int v, int p=-1, int w=0) {
	int k = 1;
	for (int i = 0; i < G[v].size(); i++) {
		int u = G[v][i].first, w = G[v][i].second;
		if (u != p) k += dfs(u, v, w);
	}
	distsum += w*(n-k)*k;
	return k;
}

