/*
 * discrete_p16_26.cxx
 *
 *  Created on: 2012-9-15
 *      Author: HalFtaN
 */

#include <cstdio>
#include <cstdlib>

int main(void) {
	unsigned i = 0;
	unsigned a = 128, b = 2, c = 1;
	int sum = 0;
	for (; i < 256; i++) {
		if (i & a)
			sum++;
		else if ((~i & b) && (~i & c))
			sum++;
	}
	printf("%d\n", sum);
	fflush(0);
}

