typedef long long ll;
int powmod(int b, int e, int m) {
	return e>1 ? (ll)powmod((ll)b*b%m, e/2, m)*(e&1 ? b : 1)%m : (e ? b : !!b);
}

template<int M, int b, int N> struct Hash { // <MOD, BASE, MAXLENGTH>
	static int B_[2*N]; constexpr static int *B = B_+N;
	int h; Hash(ll h_ = 0) { h = h_ % M; } operator int() const { return h; }
	inline Hash append(int ch, int i) const { return h + (ll) ch * B[i]; }
	Hash subtract(int hl, int i) const { return (ll) (h - hl + M) * B[-i-1]; }
	static void genBase() {
		B[0] = 1, B[-1] = powmod(b, M-2, M); // b^-1 %M = b^(M-2) %M
		for (int i = 1; i < N; i++)
			B[i] = (ll) B[i-1] * b % M, B[-i-1] = (ll) B[-i] * B[-1] % M;
	}
}; template<int M, int b, int N> int Hash<M,b,N>::B_[2*N]; // genBase() to init

#define HMAX 1000005
typedef Hash<1000000007, 101, HMAX> Hash1;
typedef Hash<1000000021, 149, HMAX> Hash2;
struct SHash {
	Hash1 h1; Hash2 h2;
	operator ll () const { return (ll(h1)<<32)|h2; }
	SHash(ll h) { h1 = h>>32, h2 = h&0xffffffff; }
	SHash(Hash1 h1 = 0, Hash2 h2 = 0): h1(h1), h2(h2) {}
	SHash append(int ch, int i) { return SHash(h1.append(ch, i), h2.append(ch, i)); }
	SHash subtract(SHash h, int i) { return SHash(h1.subtract(h.h1, i), h2.subtract(h.h2, i)); }
	static void genBase() { Hash1::genBase(); Hash2::genBase(); }
};
