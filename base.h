#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#include <memory>
#include <utility>
#include <functional>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <iterator>
#include <type_traits>
#include <typeinfo>

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <cassert>

using namespace std;

class test_suite {
	typedef function<void()> fn_type;
	typedef map<string, fn_type> test_list;

	test_list suite;
	unsigned id;

public:
	test_suite():
		id(0)
	{
	}

	template <typename T>
	unsigned add(string const &name, T testCase) {
		suite[name] = fn_type(testCase);
		return id++;
	}

	void run() {
/*
		for(auto &test: suite) {
/*/
		for(auto i = suite.begin(); i != suite.end(); ++i) {
//*/
			auto &test = *i;

			try {
				test.second();
			}
			catch(exception &e) {
				cerr << "Test " << test.first << " failed ["
					<< typeid(e).name() << "]: " << e.what()
					<< endl;
			}
		}
	}

	static test_suite &singleton() {
		static test_suite instance;
		return instance;
	}
};

template <typename T>
unsigned add_test(string const &name, T test) {
	return test_suite::singleton()
		.add(name, test);
}

template <typename T>
class matrix {
	typedef vector<T> array;
	typedef typename array::reference reference;

	array m;
	typename array::size_type w;
	typename array::size_type h;

public:
	typedef typename vector<T>::size_type size_type;

	matrix(size_type width, size_type height, T const &value):
		m(width * height, value),
		w(width),
		h(height)
	{
	}

	reference operator()(size_type const x, size_type const y) {
		return m[y * w + x];
	}

	reference const operator()(size_type const x, size_type const y) const {
		return m[y * w + x];
	}

	size_type const width() const { return w; }
	size_type const height() const { return h; }
};
