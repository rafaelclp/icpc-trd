#define st_left(idx) (2*(idx)+1)
#define st_right(idx) (2*(idx)+2)
#define st_middle(left,right) (((left)+(right))/2)
template<class T, int MAXSIZE>
class segtree {
	void from_array (T* v, int idx, int left, int right) {
		if (left != right) {
			from_array(v, st_left(idx), left, st_middle(left,right));
			from_array(v, st_right(idx), st_middle(left,right)+1, right);
			tree[idx] = tree[st_left(idx)] + tree[st_right(idx)];
		} else
			tree[idx] = v[left]; // para clear(), mudar v[left] para 0
	}
	T read (int i, int j, int idx, int left, int right) {
		if (i <= left && right <= j) return tree[idx];
		if (j < left || right < i) return 0;
		return read(i, j, st_left(idx), left, st_middle(left,right)) +
			read(i, j, st_right(idx), st_middle(left,right)+1, right);
	}
	void set (int x, T& v, int idx, int left, int right) {
		if (x < left || right < x) return;
		if (left != right) {
			set(x, v, st_left(idx), left, st_middle(left,right));
			set(x, v, st_right(idx), st_middle(left,right)+1, right);
			tree[idx] = tree[st_left(idx)] + tree[st_right(idx)];
		} else
			tree[idx] = v;
	}
public:
	T* tree; int size; segtree() { tree = new T[4*MAXSIZE]; }
	inline void from_array(T array[]) { from_array(array, 0, 0, size-1); }
	inline T read(int i, int j) { return read(i, j, 0, 0, size-1); }
	inline void set(int x, T v) { set(x, v, 0, 0, size-1); }
}; // int main () { segtree<int, MAXN> tree; tree.size = N; }
// nota: é necessário limpar a segtree antes de usar!!
