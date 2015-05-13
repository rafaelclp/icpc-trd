// Searchs for a pattern P in a string T.
// Running time: O(n)

string P, T; // Pattern, Text
int F[MAXN]; // Failure Function
void kmpPreprocess() { // Builds F[]
	int i = 0, j = -1; F[0] = -1; // starting values
	while (i < (int)P.size()) { // pre-process the pattern string P
		while (j >= 0 && P[i] != P[j]) j = F[j]; // if different, reset j using F
		i++; j++; // if same, advance both pointers
		F[i] = j; // observe i = 8, 9, 10, 11, 12 with j = 0, 1, 2, 3, 4
	}
} // in the example of P = "SEVENTY SEVEN" above

int kmpSearch() { // this is similar as kmpPreprocess(), but on string T
	int ret = 0, i = 0, j = 0; // starting values
	while (i < (int)T.size()) { // search through string T
		while (j >= 0 && T[i] != P[j]) j = F[j]; // if different, reset j using F
		i++; j++; // if same, advance both pointers
		if (j == (int)P.size()) { // a match found when j == m
			ret++; // printf("P is found at index %d in T\n", i - j);
			j = F[j]; // prepare j for the next possible match
		}
	}
	return ret;
}

