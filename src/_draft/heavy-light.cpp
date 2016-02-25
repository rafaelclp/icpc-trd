namespace HL {
	#define MAXN 10000
	vector<int> adj[MAXN];
	int depth[MAXN], parent[MAXN], size[MAXN], pathOf[MAXN];
	struct { // some utils to handle Heavy-Light paths
		vector<int> tbNodes; // top-bottom nodes
		inline void push(int v) { tbNodes.push_back(v); }
		inline int topNode() { return tbNodes.front(); }
		inline int bottomNode() { return tbNodes.back(); }
		inline int parentNode() { return parent[topNode()]; }
		inline int length() { return tbNodes.size(); }
		inline int topDepth() { return depth[topNode()]; }
		inline int bottomDepth() { return depth[bottomNode()]; }
		inline int pos(int v) { return depth[v] - depth[topNode()]; }
		inline void build() { /* build stuff in path (maybe a segtree?) */ }
		inline int query(int a, int b) { /* solve query in this path */ }
	} path[MAXN];
	#define getPath(v) path[pathOf[v]]
	void clear(int n) { while (n--) adj[n].clear(), path[n].tbNodes.clear(); }
	void buildTree(int v=0, int p=-1) {
		parent[v] = p, size[v] = 1, depth[v] = (p<0 ? 0 : depth[p] + 1);
		for (int u : adj[v]) if (u != p) buildTree(u, v), size[v] += size[u];
	}
	void buildHL(int v=0, int p=-1) {
		path[pathOf[v] = (p<0 || size[p]>2*size[v]) ? v : pathOf[p]].push(v);
		for (int u : adj[v]) if (u != p) buildHL(u, v);
		if (pathOf[v] == v) path[v].build();
	} // to build() everything: buildTree(), buildHL();
	int lca(int v, int u) {
		for (; pathOf[v] != pathOf[u]; v = getPath(v).parentNode())
			if (getPath(v).topDepth() < getPath(u).topDepth()) swap(v, u);
		return depth[v] < depth[u] ? v : u;
	}
}; using namespace HL;
