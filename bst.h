#ifndef INCLUDED__bst_h
#define INCLUDED__bst_h

#include <memory>
#include <algorithm>
#include <iostream>

#include <cassert>

using namespace std;

template <typename T>
class node {
	unique_ptr<node> l;
	unique_ptr<node> r;
	T v;

public:
	node(T const &value, node *left = 0, node *right = 0):
		l(left),
		r(right),
		v(value)
	{
	}

	node const *left() const { return l.get(); }
	node *left() { return l.get(); }
	node *left(node *left) {
		l.reset(left);
		return left;
	}

	node const *right() const { return r.get(); }
	node *right() { return r.get(); }
	node *right(node *right) {
		r.reset(right);
		return right;
	}

	T const &value() const { return v; }
	T &value() { return v; }
};

unique_ptr<node<int>> build_balanced_tree() {
	return unique_ptr<node<int>>(
		new node<int>(4,
			new node<int>(2,
				new node<int>(1),
				new node<int>(3)
			),
			new node<int>(6,
				new node<int>(5),
				new node<int>(7)
			)
		)
	);
}

unique_ptr<node<int>> build_unbalanced_tree() {
	return unique_ptr<node<int>>(
		new node<int>(2,
			new node<int>(7,
				new node<int>(2),
				new node<int>(6,
					new node<int>(5),
					new node<int>(11)
				)
			),
			new node<int>(5,
				0,
				new node<int>(9,
					new node<int>(4)
				)
			)
		)
	);
}

#endif // INCLUDED__bst_h
