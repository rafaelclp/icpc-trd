def josephus(n, k): # 1..n
	r, i = 0, 2
	while i <= n:
		r, i = (r + k) % i, i + 1
	return r + 1

def josephus2(n): # 1..n, k=2
	from math import log
	return 2*(n - 2**(int(log(n,2))))+1