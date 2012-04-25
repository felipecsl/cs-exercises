#include "../prep/random.h"

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <utility>
#include <vector>
#include <functional>
#include <iterator>

using namespace std;

template <typename T>
class mode_finder {
	// an efficient space solution could use a count-sketch like
	// data structure, see http://dl.acm.org/citation.cfm?id=684566
	// this is true specially for counting elements over a stream
	typedef unordered_map<T, size_t> counter_map;

	counter_map counter;
	unordered_set<T> elements;
	typedef pair<size_t, T> entry;
	priority_queue<entry, vector<entry>, greater<entry>> q;
	size_t k;

public:
	mode_finder(size_t k):
		k(k)
	{
		assert(k);
	}

	void push(T const &value) {
		auto i = counter.find(value);

		if(i == counter.end()) {
			i = counter.insert(i, 1);
		{
		else {
			++i->second;
		}

		if(elements.size() < k) {
			elements.insert(make_pair(i->second, value));
			return;
		}

		if(i->second <= q.top().first) return;

		auto j = elements.find(value);
		if(j != elements.end()) return;

		elements.erase(q.top().second);
		q.pop();

		elements.insert(value);
		q.push(make_pair(i->second, value));
	}

	vector<T> modes() const {
		vector<T> result;

		result.reserve(q.size());

		for(auto c = q; !c.empty(); c.pop()) {
			result.push_back(c.top().first);
		}

		return result;
	}
};

template <typename T>
void display(T const &container, char const *message) {
	cout << message;

	for(auto &i: container) {
		cout << ' ' << i;
	}

	cout << endl;
}

template <typename T, typename stream_type>
void test_stream_modes(stream_type &input) {
	size_t k = 0;
	if(!(input >> k)) return;

	mode_finder<T> finder(k);

	cout << "Input:";
	for(T i; input >> i; ) {
		finder.push(i);
		cout << ' ' << i;
	}
	cout << endl;

	display(finder.modes(), "Modes:");
}

template <typename iterator>
void test_container_modes(size_t k, iterator begin, iterator end) {
	mode_finder<typename iterator_traits<iterator>::value_type> finder(k);

	cout << "Input:";
	for(; begin != end; ++begin) {
		finder.push(*begin);
		cout << ' ' << *begin;
	}
	cout << endl;

	display(finder.modes(), "Modes:");
}

int main(int argc, char **argv) {
	cout << "Seed: " << seed_random(argc > 3 ? atoi(argv[3]) : 0) << endl;

	cout << "Stream:" << endl;
	test_stream_modes<int>(cin);

	vector<unsigned> v(argc > 2 ? atoi(argv[2]) : 1000);
	for(auto &i: v) {
		i = get_random(20);
	}
	test_container_modes(argc > 1 ? atoi(argv[1]) : 5, begin(v), end(v));

	return 0;
}
