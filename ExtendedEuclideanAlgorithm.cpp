// Given integers a and b
// the extended Euclidean algorithm computes the
// greatest common divisor of a and b, and also
// the coefficients of Bezout's identity, which 
// are integers x and y s.t ax + by = gcd(a,b)

#include <cstdio>

typedef long long ll; 

using namespace std;

void ExtendedEuclidAlgorithm(ll a, ll b, long long & x, long long  & y, long long & d) {
	ll q, aux;
	ll r0 = a;
	ll r1 = b;
	ll s0 = 1;
	ll s1 = 0;
	ll t0 = 0;
	ll t1 = 1;

	while (r1) {
		q = r0/r1;
		aux = r1;
		r1 = r0 - q*r1;
		r0 = aux;
		aux = s1;
		s1 = s0 - q*s1;
		s0 = aux;
		aux = t1;
		t1 = t0 - q*t1;
		t0 = aux;
	}
	d = r0;
	x = s0;
	y = t0;
}

int main() {
	ll a, b, x, y, d;
	scanf("%lld %lld", &a, &b);
	ExtendedEuclidAlgorithm(a, b, x, y, d);
	printf("(%lld)x(%lld) + (%lld)x(%lld) = %lld\n", a, x, b, y, d);
}
		

