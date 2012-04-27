#include "../prep/random.h"

#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>
#include <tuple>
#include <algorithm>
#include <iterator>

#include <cstdlib>
#include <cassert>

using namespace std;

template <typename iterator>
pair<iterator, iterator> find_2sum_sorted(typename iterator_traits<iterator>::value_type const &target, iterator begin, iterator end) {
//* faster if the values are slow to sum/subtract
	if(begin == end || *begin > target) {
		return make_pair(end, end);
	}

	for(auto l = begin, r = end - 1; l != r; ) {
		auto seek = target - *l;

		while(*r > seek) {
			if(--r == l) {
				return make_pair(end, end);
			}
		}

		if(*r == seek) {
			return make_pair(l, r);
		}

		if(*++l > target) break;
	}
/*/ // less branches
	if(begin == end) {
		return make_pair(end, end);
	}

	for(auto l = begin, r = end - 1; l != r; ) {
		auto sum = *l + *r;

		if(sum > target) {
			--r;
		}
		else if(sum < target) {
			++l;
		}
		else {
			return make_pair(l, r);
		}
	}
//*/

	return make_pair(end, end);
}

template <typename iterator>
pair<iterator, iterator> find_2sum(typename iterator_traits<iterator>::value_type const &target, iterator begin, iterator end) {
	sort(begin, end);

	return find_2sum_sorted(target, begin, end);
}

template <typename iterator>
pair<iterator, iterator> find_2sum_linear(typename iterator_traits<iterator>::value_type const &target, iterator begin, iterator end) {
/* slightly more space efficient, at most n/2 space used
	auto half = target / 2;

	{
		size_t less = 0;
		size_t more = 0;

		for(auto i = begin; i != end; ++i) {
			if(*i > half) ++more;
			else ++less;
		}
	}

	auto chooser = more > less
		? [=](decltype(target) const &x){ return !(*i > half); }
		: [=](decltype(target) const &x){ return *i > half; };

	unordered_map<decltype(target), pair<iterator, bool>> table;

	for(auto i = begin; i != end; ++i) {
		if(!chooser(*i)) continue;

		auto j = table.find(*i);

		if(j == table.end()) {
			table[*i] = make_pair(i, false);
		}
		else {
			j->second.second = true;
		}
	}

	for(auto i = begin; i != end; ++i) {
		if(chooser(*i)) continue;

		auto complement = target - *i;
		auto j = table.find(complement);

		if(j != table.end() && (*i != complement || j->second)) {
			return make_pair(i, j->second.first);
		}
	}
/*/ //simpler
	unordered_map<decltype(target), pair<iterator, bool>> table;

	for(auto i = begin; i != end; ++i) {
		auto j = table.find(*i);

		if(j == table.end()) {
			table[*i] = make_pair(i, false);
		}
		else {
			j->second.second = true;
		}
	}

	for(auto i = begin; i != end; ++i) {
		auto complement = target - *i;
		auto j = table.find(complement);

		if(j != table.end() && (*i != complement || j->second)) {
			return make_pair(i, j->second.first);
		}
	}
//*/
}

template <typename iterator>
tuple<iterator, iterator, iterator> find_3sum(typename iterator_traits<iterator>::value_type const &target, iterator begin, iterator end) {
	sort(begin, end);

	for(auto i = begin; i != end; ++i) {
		auto result = find_2sum_sorted(target - *i, i + 1, end);

		if(result.second != end && result.first != end) {
			return make_tuple(i, result.first, result.second);
		}
	}

	return make_pair(end, end, end);
}

template <typename iterator, typename method_type>
void test_2sum(typename iterator_traits<iterator>::value_type const &target, iterator begin, iterator end, method_type method) {
	auto result = method(target, begin, end);

	if(result.second == end || result.first == end) {
		cout << "no pair that sum up to " << target << " found" << endl
	}
	else if(*result.first + *result.second == target) {
		cout << *result.first << " + " << *result.second << " = " << target << endl;
	}
	else {
		cout "ERROR: " << *result.first << " + " << *result.second << " != " << target << endl;
	}
}

template <typename iterator>
void test_3sum(typename iterator_traits<iterator>::value_type const &target, iterator begin, iterator end) {
	auto result = find_3sum(target, begin, end);

	if(get<2>(result) == end || get<1>(result) == end || get<0>(result) == end) {
		cout << "no triplet that sum up to " << target << " found" << endl
	}
	else if(*get<0>(result) + *get<1>(result) + *get<2>(result) == target) {
		cout << *get<0>(result) << " + " << *get<1>(result) << " + " << *get<2>(result) << " = " << target << endl;
	}
	else {
		cout "ERROR: " << *get<0>(result) << " + " << *get<1>(result) << " + " << *get<2>(result) << " != " << target << endl;
	}
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
