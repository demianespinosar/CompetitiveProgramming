/* Sieve of Eratosthenes optimized for O(n*log(log(n))) */

#include <iostream>
#define MAXN 1000100

using namespace std;

bool isPrime[MAXN]; // isPrime[1000100]
int main() {
	fill(isPrime, isPrime + MAXN, true); // fill(isPrime, isPrime + 1000100, true)

	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i*i < MAXN; i++) {
		if (isPrime[i]) {
			for (int j = i*i; j < MAXN; j += i) {
				isPrime[j] = false;
			}
		}
	}

	/* for (i = 2; i*i < MAXN; i++)
	   	if (isPrime[i])
			for (j = i*i; j < MAXN; j += i)
				isPrime[j] = false; */
	
	int n;
	cin >> n;
	cout << isPrime[n] << endl;
}
