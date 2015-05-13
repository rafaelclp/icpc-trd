def josephus(n, k): # 1..n
	r, i = 0, 2
	while i <= n:
		r, i = (r + k) % i, i + 1
	return r + 1

def josephus(n, k): # 1..n
	if n == 1: return 1
	return ((josephus(n - 1, k) + k - 1) % n) + 1

def josephus(n,k): # 0..n-1
	if n == 1: return 0
	if k == 1: return n-1
	if k > n: return (josephus(n - 1, k) + k) % n
	r = josephus(n - n/k, k) - n%k
	return r + (n if r < 0 else r/(k-1))

def josephus2(n): # 1..n, k=2
	from math import log
	return 2*(n - 2**(int(log(n,2))))+1