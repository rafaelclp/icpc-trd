// Calculates lca(a,b) in a tree in O(log n).
// Running time: O(log n) + pre-computing O(n log n)

const int MAXN=1000005, LOGMAXN=2+log2(MAXN);
vector<int> G[MAXN];
int parent[LOGMAXN][MAXN], depth[MAXN];

// Generates parent[][] and depth[]; call dfs(root)
void dfs(int v, int p=-1) {
	depth[v] = (p >= 0 ? depth[p] + 1 : 0);
	parent[0][v] = p;
	for (int i = 0, l = 31-__builtin_clz(depth[v]); i <= l; i++)
		parent[i+1][v] = parent[i][parent[i][v]];
	for (int i = 0; i < G[v].size(); i++)
		if (G[v][i] != p)
			dfs(G[v][i], v);
}

// Gets lca(a,b)
int lca(int a, int b) {
	// puts both on same depth
	if (depth[a] > depth[b]) swap(a, b);
	for (int d = depth[b] - depth[a]; d; d -= d&-d)
		b = parent[__builtin_ctz(d)][b];
	if (a == b) return a;
	// goes up as much as possible keeping a != b
	for (int up = 31-__builtin_clz(depth[a]); up >= 0; up--)
		if (parent[up][a] != parent[up][b])
			a = parent[up][a], b = parent[up][b];
	return parent[0][a]; // a != b, but parent(a) = parent(b) = lca
}
