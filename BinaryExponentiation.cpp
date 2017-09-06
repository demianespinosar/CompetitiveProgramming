/* Given two non-negative integers a, n
   return a^n modulo MOD, which is also given. O(log(n)) */

#include <cstdio> //#include <iostream>

long long binaryExp(long long a, long long n, long long MOD) {
	long long res = 1;
	while (n) {  // while (n != 0). In this case checking for n > 0 since n is non negative.
		if (n%2) { // if (n%2 != 0). In this case 1 or 0.
			res = (res * a) % MOD;
		}
		a = (a * a) % MOD;
		n = n/2; // n = n >> 1. Shift bit "1101" ---> "110".  
	}
	return res;
}


long long a, n, MOD;
int main() {
	scanf("%lld %lld %lld", &a, &n, &MOD); // cin >> a >> n >> M;
	printf("%lld\n", binaryExp(a, n, MOD)); // cout << binaryExp(a, n, MOD) << endl;
}
