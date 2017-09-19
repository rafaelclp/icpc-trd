typedef long long ll;
int powmod(int b, int e, int m) {
	return e>1 ? (ll)powmod((ll)b*b%m, e/2, m)*(e&1 ? b : 1)%m : (e?b:!!b);
}

template<int M, int b, int B[], int Bn[]> struct Hash {
	int h; Hash(int h = 0): h(h) {}
	operator int() const { return h; }
	inline Hash append(int ch, int i) { return (h + (ll) ch * B[i]) % M; }
	inline Hash subtract(int hl, int i) { return (ll) (h - hl + M) * Bn[i+1] % M; }
	static void genBase(int n) { // (CALL ONCE IN MAIN TO INIT!!)
		B[0] = Bn[0] = 1, Bn[1] = powmod(b, M-2, M); // b^-1 %M = b^(M-2) %M
		for (int i = 1; i < n; i++)
			B[i] = (ll) B[i-1] * b % M, Bn[i] = (ll) Bn[i-1] * Bn[1] % M;
	}
}; // template <MOD, BASE, B[i] = BASE^i, Bn[i] = BASE^-i>

#define HMAX 1000005
int HB1[HMAX], HBn1[HMAX]; typedef Hash<1000000007, 101, HB1, HBn1> Hash1;
int HB2[HMAX], HBn2[HMAX]; typedef Hash<1000000021, 149, HB2, HBn2> Hash2;

struct SHash {
	Hash1 h1; Hash2 h2;
	operator long long () const { return (ll(h1)<<32)|h2; }
	SHash(Hash1 h1 = 0, Hash2 h2 = 0): h1(h1), h2(h2) {}
	inline SHash append(int ch, int i) {
		return SHash(h1.append(ch, i), h2.append(ch, i));
	}
	inline SHash subtract(SHash h, int i) {
		return SHash(h1.subtract(h.h1, i), h2.subtract(h.h2, i));
	}
	static void genBase(int n) { Hash1::genBase(n); Hash2::genBase(n); }
};
