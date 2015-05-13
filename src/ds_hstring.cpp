Gerando bases B:
	B[i] = BASE^i % m, 0 <= i
	B^[-i] = BASE^(m-1-i) % m, 1 <= i
Gerando hash H para uma string S de tamanho n+1:
	H = (S[0] + S[1]*B[1] + ... + S[n]*B[n]) % m
	H[n] = (H[n-1] + S[n]*B[n]) % m
Calculando hash h no intervalo [a,b]:
	h = (H[b] - H[a-1] + m) * B[-a] % m
