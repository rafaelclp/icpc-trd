// Finds # of rotations in str to find the lexicographically smaller string
// Running time: O(n)

int lexRot(string str) {
	int n = str.size(), ini=0, fim=1, rot=0;
	str += str;
	while(fim < n && rot+ini+1 < n)
		if (str[ini+rot] == str[ini+fim]) ini++;
		else if (str[ini+rot] < str[ini+fim]) fim += ini+1, ini = 0;
		else rot = max(rot+ini+1, fim), fim = rot+1, ini = 0;
	return rot;
}
