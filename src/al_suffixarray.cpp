// Calculates the suffix array (and LCP) of a string.
// Running time: O(n log n)

int sa[MAXN], invsa[MAXN], n, sz;
inline bool cmp(int a, int b) { return invsa[a+sz]<invsa[b+sz]; }
void sort_sa(int a, int b) {
	if (a == b) return;
	int pivot = sa[a + rand()%(b-a)], c = a, d = b;
	for (int i = c; i < b; i++)
		if (cmp(sa[i], pivot)) swap(sa[i], sa[c++]);
	for (int i = d-1; i >= a; i--)
		if (cmp(pivot, sa[i])) swap(sa[i], sa[--d]);
	sort_sa(a, c);
	for (int i = c; i < d; i++) invsa[sa[i]] = d-1;
	if (d-c == 1) sa[c] = -1;
	sort_sa(d, b);
}
void suffix_array(char* s) { // could be int*s; but del strlen(n)
	n = strlen(s), invsa[n] = -1;
	for (int i = 0; i < n; i++) sa[i] = i, invsa[i] = s[i];
	sz = 0; sort_sa(0, n);
	for (sz = 1; sz < n; sz *= 2)
		for (int i = 0, j = i; i < n; i = j)
			if (sa[i] < 0) {
				while (sa[j] < 0) j += (-sa[j]);
				sa[i] = -(j-i);
			} else sort_sa(i, j=invsa[sa[i]]+1);
	for (int i = 0; i < n; i++) sa[invsa[i]] = i;
}
int lcp[MAXN];
void calc_lcp(char* s) { // could be int*s
	for (int i = 0, l = 0; i < n; i++, l = max(0, l-1)) {
		if (invsa[i] == 0) continue;
		int j = sa[invsa[i]-1];
		while (max(i+l, j+l) < n && s[i+l] == s[j+l]) l++;
		lcp[invsa[i]] = l;
	}//for(int i=0;i+1<n;i++)lcp[i]=lcp[i+1];lcp[n-1]=0;
}
