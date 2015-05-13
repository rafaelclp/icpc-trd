// Finds the longest palindrome in a string s. Notice that array P[i] will
// store the radius of the longest palindrome centered at T[i].
// Running time: O(n)

// Transform S into T. Example: S = "abba", T = "^#a#b#b#a#$"
// ^ and $ signs are sentinels to avoid bounds checking
string preProcess(string& s) {
	int n = s.length();
	if (n == 0) return "^$";
	string ret = "^";
	for (int i = 0; i < n; i++)
		ret += "#" + s.substr(i, 1);
	ret += "#$";
	return ret;
}
string longestPalindrome(string& s) {
	string T = preProcess(s);
	int n = T.length(), C = 0, R = 0;
	int *P = new int[n]; // may be useful OUTSIDE this function
	for (int i = 1; i < n-1; i++) {
		int i_mirror = (C<<1)-i; // i' = C-(i-C)
		P[i] = (R > i) ? min(R-i, P[i_mirror]) : 0;
		// Attempt to expand palindrome centered at i
		while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
			P[i]++;
		// If palindrome centered at i expand past R,
		// adjust center based on expanded palindrome.
		if (i + P[i] > R) {
			C = i;
			R = i + P[i];
		}
	}
	// Find the maximum element in P.
	int maxLen = 0, centerIndex = 0;
	for (int i = 1; i < n-1; i++)
		if (P[i] > maxLen) {
			maxLen = P[i];
			centerIndex = i;
		}
	delete[] P;
	return s.substr((centerIndex - 1 - maxLen)/2, maxLen);
}
