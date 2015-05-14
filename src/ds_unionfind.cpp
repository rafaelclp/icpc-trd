struct UnionFind {
	int *rank, *parent, size;
	UnionFind(int msize) { rank = new int[msize]; parent = new int[msize]; }
	void init(int msize) {
		size = msize;
		for (int i = 0; i < size; i++)
			parent[i] = i, rank[i] = 1;
	}
	int find(int node) {
		if (node == parent[node]) return node;
		return parent[node] = find(parent[node]);
	}
	void union_(int a, int b) {
		a = find(a), b = find(b);
		if (rank[a] <= rank[b]) parent[a] = b, rank[b] += rank[a];
		else parent[b] = a, rank[a] += rank[b];
	}
}; // int main() { UnionFind uf(MAXN); uf.init(n); }
