// Running time: O(n), requires: Tarjan
// Create edges using add_2sat_edge(v_not ? NOT(v) : v, u_not ? NOT(u) : u);

#define NOT(v) ((v)^1)
inline void add_2sat_edge(int v, int u) {
	G[NOT(v)].push_back(u), G[NOT(u)].push_back(v);
}
bool _2sat(int N, int st=0) {
	find_scc(N, st);
	for (int i = st; i < st+N; i += 2) if (scc[i] == scc[NOT(i)]) return false;
	return true;
}
