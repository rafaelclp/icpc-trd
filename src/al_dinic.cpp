// Calculates the max flow of a graph.
// Running time: O(V²E)

const int MAXN = 5005, MAXE = 30005;
typedef long long lint;
struct Graph {
	int n, m; // << set n (number of vertices), vertices are 0-indexed
	vector<int> adj[MAXN];
	pair<int, int> edges[2*MAXE];
	inline void add_edge(int v, int u, int vu, int uv=0) {
		edges[m] = make_pair(u, vu); adj[v].push_back(m++);
		edges[m] = make_pair(v, uv); adj[u].push_back(m++);
	}
	int dis[MAXN], pos[MAXN]; 
	int fluxo[2*MAXE];
	int src, dst; // << set these
} G;
bool dinic_bfs(Graph& g) {
	queue<int> qu;
	qu.push(g.src);

	for (int i = 0; i < g.n; i++) g.dis[i] = -1;
	g.dis[g.src] = 0;

	while (!qu.empty()) {
		int v = qu.front(); qu.pop();
		for (int i = 0; i < g.adj[v].size(); i++) {
			int e = g.adj[v][i];
			int u = g.edges[e].first;
			int c = g.edges[e].second;
			if (c > 0 && g.dis[u] == -1) {
				g.dis[u] = g.dis[v] + 1;
				qu.push(u);
			}
		}
	}
	return g.dis[g.dst] != -1;
}
int dinic_dfs(int v, int flow, Graph& g) {
	if (v == g.dst) return flow;

	for (int& i = g.pos[v]; i < g.adj[v].size(); i++) {
		int e = g.adj[v][i];
		int u = g.edges[e].first;
		int c = g.edges[e].second;
		if (c > 0 && g.dis[u] == g.dis[v] + 1) {
			int flow_ = dinic_dfs(u, min(flow, c), g);
			if (flow_ > 0) {
				g.edges[e].second -= flow_;
				g.edges[e^1].second += flow_;
				return flow_;
			}
		}
	}
	return 0;
}
lint dinic(Graph& g) {
	lint max_flow = 0;
	while (dinic_bfs(g)) {
		for (int i = 0; i < g.n; i++) g.pos[i] = 0;
		while (int flow = dinic_dfs(g.src, INT_MAX, g))
			max_flow += flow;
	}
	return max_flow;
}
int main() {
	G.n = 6; // number of vertices: 6 = 0..5
	G.src = 1; G.dst = 3; // Vertices: source (1) and sink (3)
	G.add_edge(1, 3, 5, 9); // adds edge 1->3 with cap. 5 and 3->1 with cap. 9
	printf("Max flow: %d\n", dinic(G));
	for (int i = 0; i < G.n; i++) printf("flow[%d] = %d\n", i, G.fluxo[i]);
}
