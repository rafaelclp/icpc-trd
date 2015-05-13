// Builds array z[], such that z[i] is the length of the longest substring
// starting at s[i] that is also a prefix of s.
// Running time: O(n)

// note: MAXN > maxLen(T)+maxLen(S)
int z[MAXN]; // s[:z[i]] == s[i:i+z[i]]
void z_algorithm(string& s) {
	int n = s.length(), L = 0, R = 0;
	for (int i = 1; i < n; i++) {
		if (i > R) {
			L = R = i;
			while (R < n && s[R-L] == s[R]) R++;
			z[i] = (R--)-L;
		} else {
			int k = i-L;
			if (z[k] < R-i+1)
				z[i] = z[k];
			else {
				L = i;
				while (R < n && s[R-L] == s[R]) R++;
				z[i] = (R--)-L;
			}
		}
	}
}
// finds the indexes of all occurences of T in S
void indexesOf(string T, string& S, vector<int>& v) {
	int m = T.length();
	T += "$" + S;
	z_algorithm(T);
	for (int i = m+1; i < T.length(); i++)
		if (z[i] == m)
			v.push_back(i-m-1);
}
