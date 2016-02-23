int segPool[2*MAXN]; int segPoolIdx; // way faster than new/delete/malloc/free
inline int* newSegTMem(int n) { return &segPool[(segPoolIdx+=(n<<1))-(n<<1)]; }
#define clearSegTMem() (segPoolIdx=0) // clear after every testcase
template<class T> struct segtree {
	int n; T *t; // t[1] is root, t[0] is not used
	inline T op(T &lval, T &rval) { return max(lval, rval); } // CHANGE THIS!!
	inline void alloc(int size) { t = newSegTMem(n = size); }
	inline void build(vector<T> &v) { // you may want to remove call to alloc!
		alloc(v.size()); for (int i = 0; i < n; i++) t[i+n] = v[i];
		for (int i = n - 1; i > 0; i--) t[i] = op(t[i<<1], t[i<<1|1]);
	}
	inline void modify(int p, const T &val) {
		for (t[p += n] = val; p >>= 1; ) t[p] = op(t[p<<1], t[p<<1|1]);
	}
	inline T query(int l, int r) { // [l, r); for single element, get t[n+idx]
		T res = 0; // nil
		for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if (l&1) res = op(res, t[l++]); // if order really matters, create
			if (r&1) res = op(t[--r], res); // resl and resr and merge in retn
		}
		return res; // op(resl, resr)
	}
}; // (1) segtree<int> seg; (2) seg.build(v); OR seg.alloc(n); (doesn't clear)
