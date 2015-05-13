// Calculates fibonacci numbers.
// Running time: O(__builtin_popcount(n-1)) = O(log n)

#define LOGMAXN 63
long long f0, f1, faux;
long long fib2[LOGMAXN+1][2]={{0,1}}; // fib2[i]={Fib(n-1),Fib(n)}, n=2^i
template<int MOD> void generate_fib2() {
	for (int i = 1; i <= LOGMAXN; i++) {
		fib2[i][1] = (fib2[i-1][1]*(((fib2[i-1][0]<<1)+fib2[i-1][1])))%MOD;
		fib2[i][0] = (fib2[i][1]-(fib2[i-1][0]*(((fib2[i-1][1]<<1)-fib2[i-1][0]+MOD)%MOD))%MOD+MOD)%MOD;
	}
}
template<int MOD> inline long long fib(long long n) { // {0,1,1,2,...}
	if (!fib2[1][0]) generate_fib2<MOD>();
	if (!n--) return 0;
	f0 = 0, f1 = 1;
	while (n) {
		int i = __builtin_ctzll(n);
		faux = (f1*fib2[i][1] + f0*fib2[i][0]) % MOD;
		f1 = (f1*(fib2[i][0]+fib2[i][1]) + f0*fib2[i][1]) % MOD;
		f0 = faux;
		n -= 1ULL<<i;
	}
	return f1;
}
int main() {generate_fib2<1000000007>(); printf("%lld",fib<1000000007>(100));}

// Some identities:
//   F(n+1)F(n-1) - F(n)² = -1^n
//   F(n+k) = F(k)F(n+1) + F(k-1)F(n)
//   F(2n-1) = F(n)² + F(n-1)²
//   SUM(i=0 to n)[F(i)] = F(n+2) - 1
//   SUM(i=0 to n)[F(i)²] = F(n)F(n+1)
//   SUM(i=0 to n)[F(i)³] = [F(n)F(n+1)² - (-1^n)F(n-1) + 1] / 2
//   gcd(Fm, Fn) = F(gcd(m,n))
//   sqrt(5N² +- 4) is natural <-> exists natural k | F(k) = N
//   [ F(0) F(1) ] [ [0 1] [1 1] ]^n = [ F(n) F(n+1) ]
// Binet's formula:
//   g = (1 + sqrt(5)) / 2
//   Fn = g^n / sqrt(5)
//   n(F) = floor(log[g](sqrt(5)F + 1/2)), log[g] = log base g

// First 40 fibonacci numbers
//    n F(n) |  n  F(n) |  n    F(n) |  n      F(n) |  n       F(n)
//    0   0  |  8   21  | 16    987  | 24    46368  | 32   2178309
//    1   1  |  9   34  | 17   1597  | 25    75025  | 33   3524578
//    2   1  | 10   55  | 18   2584  | 26   121393  | 34   5702887
//    3   2  | 11   89  | 19   4181  | 27   196418  | 35   9227465
//    4   3  | 12  144  | 20   6765  | 28   317811  | 36  14930352
//    5   5  | 13  233  | 21  10946  | 29   514229  | 37  24157817
//    6   8  | 14  377  | 22  17711  | 30   832040  | 38  39088169
//    7  13  | 15  610  | 23  28657  | 31  1346269  | 39  63245986
