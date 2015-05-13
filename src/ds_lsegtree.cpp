// Must receive type T of each element in the tree, type R of each element
// in the input and max size of the segtree on the template. Implement the
// update and the lines with //##//. DO NOT FORGET TO CLEAR BEFORE USING!!

#define nil 0 // value that doesn't interfere
#define st_left(idx) (2*(idx)+1)
#define st_right(idx) (2*(idx)+2)
#define st_middle(left,right) (((left)+(right))/2)
template<class T, class R, int MAXSIZE>
class lsegtree {
	void from_array(T* v, int idx, int left, int right) {
		refreshr[idx] = false;
		if (left != right) {
			from_array(v, st_left(idx), left, st_middle(left,right));
			from_array(v, st_right(idx), st_middle(left,right)+1, right);
			tree[idx] = tree[st_left(idx)] + tree[st_right(idx)]; //##//
		} else
			tree[idx] = v[left];
	}
	T read(int i, int j, int idx, int left, int right) {
		update(idx, left, right);
		if (i <= left && right <= j) return tree[idx];
		if (j < left || right < i) return nil;
		return read(i, j, st_left(idx), left, st_middle(left,right)) + //##//
			read(i, j, st_right(idx), st_middle(left,right)+1, right);
	}
	void set(int i, int j, R v, int idx, int left, int right) {
		update(idx, left, right);
		if (j < left || right < i) return;
		if (i <= left && right <= j) {
			refresh[idx] = v;
			refreshr[idx] = true;
			update(idx, left, right);
		} else {
			set(i, j, v, st_left(idx), left, st_middle(left,right));
			set(i, j, v, st_right(idx), st_middle(left,right)+1, right);
			tree[idx] = tree[st_left(idx)] + tree[st_right(idx)]; //##//
		}
	}
	void update(int idx, int left, int right) {
		if (refreshr[idx]) {
			if (left != right) {
				if (!refreshr[st_left(idx)]) refresh[st_left(idx)] = 0;
				if (!refreshr[st_right(idx)]) refresh[st_right(idx)] = 0;
				refresh[st_left(idx)] += refresh[idx]; //##//
				refresh[st_right(idx)] += refresh[idx]; //##//
				refreshr[st_left(idx)] = refreshr[st_right(idx)] = true;
			}
			tree[idx] += (right-left+1)*refresh[idx]; //##//
			refreshr[idx] = false;
		}
	}
public:
	T *tree; R *refresh; bool *refreshr; int size;
	lsegtree() {
		tree = new T[4*MAXSIZE];
		refresh = new R[4*MAXSIZE];
		refreshr = new bool[4*MAXSIZE];
	}
	inline void from_array(T array[]) { from_array(array, 0, 0, size-1); }
	inline T read(int i, int j) { return read(i, j, 0, 0, size-1); }
	inline void set(int i, int j, R v) { set(i, j, v, 0, 0, size-1); }
}; // int main() { lsegtree<int,int,MAXN> l; l.size = N; l.clear(); }
