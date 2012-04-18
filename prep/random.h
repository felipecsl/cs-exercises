#ifndef INCLUDED__random_h
#define INCLUDED__random_h

#include <cstdlib>
#include <ctime>

unsigned seed_random(unsigned seed = 0) {
	if(!seed) {
		seed = std::time(0);
		if(!seed) seed = 1;
	}

	std::srand(seed);

	return seed;
}
#endif // INCLUDED__random_h
