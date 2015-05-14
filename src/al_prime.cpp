// Sieve of Eratosthenes: finds all primes up to N.
// Running time: O(N log log N)

#define MAXP 100000000 // ADJUST!
bool is_prime[MAXP+1]={0,0,1};
template<int N> void sieve() {
	for (int i = 3; i <= N; i += 2)
		is_prime[i] = true;
	for (int i = 3; i*i <= N; i += 2)
		if (is_prime[i])
			for (int j = i*i; j <= N; j += 2*i)
				is_prime[j] = false;
}

// Miller-Rabin Primality Test: tests whether a number is prime or not.
// Running time: O(k log n) for primes, huge constant

ulint llrand() { ulint a = rand(); a<<= 32; a+= rand(); return a; }
ulint mul_mod(ulint a, ulint b, ulint mod) { return a*b%mod; } //(a%m+m)%m*b%m
ulint exp_mod(ulint a, ulint e, ulint mod) {
	if (e == 0) return 1;
	ulint b = exp_mod(a,e/2,mod);
	return (e % 2 == 0) ? mul_mod(b,b,mod) : mul_mod(mul_mod(b,b,mod),a,mod);
}
int is_probably_prime(ulint n, int k=64) {
	if (n <= 1) return 0;
	if (n <= 3) return 1;
	ulint s = 0, d = n - 1;
	while ((d&1) == 0)
		d /= 2, s++;
	while (k--) {
		ulint a = (llrand() % (n - 3)) + 2;
		ulint x = exp_mod(a, d, n);
		if (x != 1 && x != n-1) {
			for (int r = 1; r < s; r++) {
				x = mul_mod(x, x, n);
				if (x == 1) return 0;
				if (x == n-1) break;
			}
			if (x != n-1) return 0;
		}
	}
	return 1;
}

// Primes less than 1000:
//      2     3     5     7    11    13    17    19    23    29    31    37
//     41    43    47    53    59    61    67    71    73    79    83    89
//     97   101   103   107   109   113   127   131   137   139   149   151
//    157   163   167   173   179   181   191   193   197   199   211   223
//    227   229   233   239   241   251   257   263   269   271   277   281
//    283   293   307   311   313   317   331   337   347   349   353   359
//    367   373   379   383   389   397   401   409   419   421   431   433
//    439   443   449   457   461   463   467   479   487   491   499   503
//    509   521   523   541   547   557   563   569   571   577   587   593
//    599   601   607   613   617   619   631   641   643   647   653   659
//    661   673   677   683   691   701   709   719   727   733   739   743
//    751   757   761   769   773   787   797   809   811   821   823   827
//    829   839   853   857   859   863   877   881   883   887   907   911
//    919   929   937   941   947   953   967   971   977   983   991   997

// Other primes (primes immediatly less than 10^x):
//  x      p   x           p   x                p   x                     p
//  1      7   6      999983  11      99999999977  16      9999999999999937
//  2     97   7     9999991  12     999999999989  17     99999999999999997
//  3    997   8    99999989  13    9999999999971  18    999999999999999989
//  4   9973   9   999999937  14   99999999999973  19   9999999999999999961
//  5  99991  10  9999999967  15  999999999999989  20  99999999999999999989
