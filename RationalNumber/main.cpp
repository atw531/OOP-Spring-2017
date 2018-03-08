#include <iostream>
#include <stdexcept>
#include <assert.h>
#include "RationalNumber.hpp"

int main() {

	RationalNumber n1 = RationalNumber(1, 4);
	RationalNumber n2 = RationalNumber(1, 2);
	RationalNumber n3 = RationalNumber(2, 4);
	RationalNumber n4 = RationalNumber(3, 4);
	RationalNumber n5 = RationalNumber(4, 4);
	RationalNumber n6 = RationalNumber(5, 4);
	RationalNumber n7 = RationalNumber(6, 4);
	RationalNumber n8 = RationalNumber(7, 4);
	RationalNumber n9 = RationalNumber(8, 4);

	assert(n1 < n2);
	assert(n2 == n3);
	assert(n1 < n3);
	assert(n2 > n1);
	assert(n3 > n1);
	assert(n1 != n9);
	assert(n3 != n7);
	assert(n2 <= n3);
	assert(n2 >= n3);
	assert(n6 <= n7);
	assert(n7 >= n6);

	RationalNumber n10 = RationalNumber(3, 8);
	assert(n2*n5 == n2);
	assert(n4*n2 == n10);
	assert(n2*n4 == n10);

	RationalNumber n11 = RationalNumber(3, 1);
	assert(n7/n2 == n11);

	RationalNumber n12 = RationalNumber(1, 1);
	assert(n4/n4 == n12);

	assert(n1 + n4 == n5);
	assert(n1 + n2 == n4);
	assert(n4 - n2 == n1);
	assert(n5 - n1 == n4);

	try {
		RationalNumber invalid = RationalNumber(1, 0);
	} catch (std::invalid_argument ex) {
		std::cout << "Invalid denominator (caught correctly)\n";
	}

	return 0;
}