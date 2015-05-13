// Finds the roots of a cubic function in the complex: ax^3+bx^2+cx+d=0
// Requires a != 0 and (b != 0 or c != 0)
// Running time: O(1), huge constant

#define cprint(n) printf("%.6lf + %.6lfi\n", (n).real(), (n).imag())
const complex<double> cbrt2 = pow(2, 1.0/3);
const complex<double> isqrt3 = complex<double>(0.0,sqrt(3.0));
complex<double> a, b, c, d, alfa, beta, delta, root1, root2, root3;
void calc_dga() {
	alfa = (-27.0*a*a*d+9.0*a*b*c-2.0*b*b*b), beta = (3.0*a*c-b*b);
	delta = pow(sqrt(alfa*alfa+4.0*beta*beta*beta) + alfa, 1.0/3);
	root1 = delta/(3.0*cbrt2*a) - cbrt2*beta/(3.0*a*delta) - b/(3.0*a);
	root2 = -1.0/(6.0*cbrt2*a)*(1.0-isqrt3)*delta+(1.0+isqrt3)*beta/(3.0*cbrt2*cbrt2*a*delta)-b/(3.0*a);
	root3 = -1.0/(6.0*cbrt2*a)*(1.0+isqrt3)*delta+(1.0-isqrt3)*beta/(3.0*cbrt2*cbrt2*a*delta)-b/(3.0*a);
}
