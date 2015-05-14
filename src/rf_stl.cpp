// QUEUE: empty, size, front, back, push, pop
// PRIORITY QUEUE: empty, size, top, push, pop
// STACK: empty, size, top, push, pop
// GENERIC (all below have at least these)
//   Iterators: begin, end, rbegin, rend
//   Capacity: empty, size, max_size
//   Modifiers: swap, clear, insert, erase

// SET
//   Operations: find, count, lower_bound, upper_bound, equal_range(=find)
// Returns <inserted element, created new(true) or already there(false)>
pair<iterator,bool> insert (const value_type& val);
// To properly take advantage of the hint:
// as begin(): val should be smaller than ALL elements in set
// as end(): val should be bigger than ALL elements in the set
// as h: h' <= val <= h, where h' is the element immediatly smaller than h
iterator insert (iterator position_hint, const value_type& val);
// Ex: s.insert(array,array+n); if [f,l) is sorted, O(n), not O(n lg n)!
template<class InputIterator> void insert(InputIterator f, InputIterator l);

void erase(iterator position);
size_type erase(const value_type& val); // returns if erased or not (0/1)
void erase(iterator first, iterator last); // removes [first,last)

iterator find(const value_type& val); // returns set::end if can't find
size_type count(const value_type& val); // basically, count(val) = has(val)
iterator lower_bound(const value_type& val); // iter to 1st element >= val
iterator upper_bound(const value_type& val); // iter to 1st element > val

// MAP
//   Operations: find, count, lower_bound, upper_bound, equal_range(=find)
//     All operations are identical to set's, but act on the key, not val!

// VECTOR
//   Access: [], at, front, back (at(n) == [n], but checks if n in [0,sz))
//   Capacity: resize, capacity, reserve
//   Modifiers: assign, push_back, pop_back

// Erases all elements; then, inserts all in [f,l), similar to set's insert
template<class InputIterator> void assign(InputIterator f, InputIterator l);
// Resizes vector to size n, then fills all elements with val
void assign (size_type n, const value_type& val);

// Inserts the element(s) immediatly BEFORE element in position
iterator insert(iterator position, const value_type& val);
void insert(iterator position, size_type n, const value_type& val);
template<class InputIterator>
	void insert(iterator position, InputIterator first, InputIterator last);

iterator erase(iterator position);
iterator erase(iterator first, iterator last);

// If v has less than n elements, expand to n and fill these with val
// If v has over n elements, just resize to n
void resize (size_type n, value_type val = value_type());

// DEQUE
//   Access: [], at, front, back (all O(1))
//   Capacity: resize
//   Modifiers: assign, push_back, push_front, pop_back, pop_front
//  Extremely similar to vector, but doesn't store ALL elements in sequence
//  (so careful about offseting a pointer), and inserts in begin in O(1).
