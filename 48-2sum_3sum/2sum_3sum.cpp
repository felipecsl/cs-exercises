#include "../prep/random.h"

#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <iterator>

#include <cstdlib>
#include <cassert>

using namespace std;

template <typename iterator>
pair<iterator, iterator> find_2sum_sorted(typename iterator_traits<iterator>::value_type const &target, iterator begin, iterator end) {
	// ...
}

template <typename iterator>
pair<iterator, iterator> find_2sum(typename iterator_traits<iterator>::value_type const &target, iterator begin, iterator end) {
	sort(begin, end);

	return find_2sum_sorted(target, begin, end);
}

template <typename iterator>
pair<iterator, iterator> find_2sum_linear(typename iterator_traits<iterator>::value_type const &target, iterator begin, iterator end) {
	// ...
}

template <typename iterator>
pair<iterator, iterator> find_3sum(typename iterator_traits<iterator>::value_type const &target, iterator begin, iterator end) {
	sort(begin, end);

	// ...
}

template <typename iterator, typename method_type>
void test_2sum(typename iterator_traits<iterator>::value_type const &target, iterator begin, iterator end, method_type method) {
	auto result = method(target, begin, end);

	// ...
}

template <typename iterator>
void test_3sum(typename iterator_traits<iterator>::value_type const &target, iterator begin, iterator end) {
	auto result = find_3sum(target, begin, end);

	// ...
}

void stdin_test() {
	int target;
	if(!(cin >> target)) return;

	cout << "Target: " << target << endl;

	vector<int> v;
	cout << "Input:";
	for(int x; cin >> x; ) {
		v.push_back(x);
		cout << ' ' << x;
	}
	cout << endl;

	test_2sum(target, begin(v), end(v), find_2sum);
	test_2sum(target, begin(v), end(v), find_2sum_linear);
	test_3sum(target, begin(v), end(v));
}

void random_test(size_t n, int k) {
	assert(n > 0);

	cout << "n = " << n
		<< endl
		<< " k = " << k
		<< endl;

	auto 2sum_target = get_random(2 * k);
	cout << "2SUM target: " << target << endl;

	auto 3sum_target = get_random(3 * k);
	cout << "3SUM Target: " << target << endl;

	vector<unsigned> v(n);
	cout << "Input:";
	while(n--) {
		v[n] = get_random(k);
		cout << ' ' << v[n];
	}
	cout << endl;

	test_2sum(2sum_target, begin(v), end(v), find_2sum);
	test_2sum(2sum_target, begin(v), end(v), find_2sum_linear);
	test_3sum(3sum_target, begin(v), end(v));
}

int main(int argc, char **argv) {
	cout << "Seed: " << seed_random(argc > 3 ? atoi(argv[3]) : 0) << endl;

	random_test(
		argc > 1 ? atoi(argv[1]) : 20,
		argc > 2 ? atoi(argv[2]) : (sqrt(n) * 2)
	);

	cout << endl;

	stdin_test();
}
