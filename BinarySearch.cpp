// Given a boolean property P defined in 1, 2, ..., N
// such that there exists an integer x in [1, N]
// that P(y) = true if and only if x <= y
// find x  

lo = 1; // The minimum value of x
hi = N; // The maximum value of x
while (lo != hi) {
	mid = (lo + hi)/2;
	if (P(y))
		hi = mid;
	else
		lo = mid + 1;
}
return lo;
