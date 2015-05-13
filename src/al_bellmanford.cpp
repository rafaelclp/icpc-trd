// Finds the minimum distance from vertex start to all the other vertices.
// In case a -oo cycle exists, returns true.
// Running time: O(VE)

#define MAXN 1000
#define $w first
#define $u second.first
#define $v second.second
vector< pair< int, pair<int, int> > > edges; // (w, (u,v))
int dist[MAXN], n;
int bellman_ford(int start) { 
	for (int i = 0; i < n; i++)
		dist[i] = INF;
	dist[start] = 0;
	for (int i = 0; i < n; i++) {
		bool edit = false;
		for (int j = 0; j < m; j++)
			if (dist[edges[j].$u] + edges[j].$w < dist[edges[j].$v]) {
				dist[edges[j].$v] = dist[edges[j].$u] + edges[j].$w;
				edit = true;
			}
		if (!edit) break;
		if (i+1 == n) return true;
	}
	return false;
} 
