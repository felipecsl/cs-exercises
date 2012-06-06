#ifndef INCLUDED_square_root_h
#define INCLUDED_square_root_h

template <typename T>
T square_root(T n, T precision, unsigned &iterations) {
	T min = 0;
	T max = n;
	T pivot = n;

	iterations = 0;

	for(T diff = precision; diff >= precision; ++iterations) {
		pivot = min + ((max - min) / 2);
		T result = pivot * pivot;

		if(result < n) {
			diff = n - result;
			min = pivot;
		}
		else {
			diff = result - n;
			max = pivot;
		}
	}

	return pivot;
}

#endif // INCLUDED_square_root_h
