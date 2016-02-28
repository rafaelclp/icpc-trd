// Tarjan algorithm: finds the strongly connected components on the graph.
// Stores the scc number for vertex v in scc[v] and amount of scc in scc_count.
// Running time: O(n)

vector<int> G[MAXN];
int idx[MAXN], idx_count, scc[MAXN], scc_count, sk[MAXN], sk_size;
bool stacked[MAXN], vis[MAXN];
void tarjan(int v) {
	int idxv = idx[v] = ++idx_count;
	sk[sk_size++] = v, stacked[v] = 1;
	for (int i = 0; i < G[v].size(); i++) {
		int u = G[v][i];
		if (!vis[u]) vis[u] = 1, tarjan(u);
		if (stacked[u]) idx[v] = min(idx[v], idx[u]);
	}
	if (idx[v] == idxv) {
		int u; scc_count++;
		do stacked[u = sk[--sk_size]] = 0, scc[u] = scc_count; while (u != v);
	}
}
void find_scc(int N, int st=0) {
	idx_count = scc_count = sk_size = 0;
	for (int i = st; i < st+N; i++) stacked[i] = vis[i] = scc[i] = 0;
	for (int i = st; i < st+N; i++) if (!vis[i]) tarjan(i);
}
