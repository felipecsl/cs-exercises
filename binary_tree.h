#ifndef INCLUDED__binary_tree_h
#define INCLUDED__binary_tree_h

#pragma message "\n\
\n\
******************************************\n\
THIS CODE SHOULD NOT be used in production\n\
it's very limited and NOT EXCEPTION SAFE\n\
it's only intended for exercising purposes\n\
******************************************\n\
"

#include <memory>

using namespace std;

template <typename T>
class bt_node {
	unique_ptr<bt_node> l;
	unique_ptr<bt_node> r;
	T v;

public:
	bt_node(T const &value, bt_node *left = 0, bt_node *right = 0):
		l(left),
		r(right),
		v(value)
	{
	}

	bt_node const *left() const { return l.get(); }
	bt_node *left() { return l.get(); }
	bt_node *left(bt_node *left) {
		l.reset(left);
		return left;
	}

	bt_node const *right() const { return r.get(); }
	bt_node *right() { return r.get(); }
	bt_node *right(bt_node *right) {
		r.reset(right);
		return right;
	}

	T const &value() const { return v; }
	T &value() { return v; }
};

unique_ptr<bt_node<int>> build_balanced_binary_tree() {
	return unique_ptr<bt_node<int>>(
		new bt_node<int>(4,
			new bt_node<int>(2,
				new bt_node<int>(1),
				new bt_node<int>(3)
			),
			new bt_node<int>(6,
				new bt_node<int>(5),
				new bt_node<int>(7)
			)
		)
	);
}

unique_ptr<bt_node<int>> build_unbalanced_binary_tree() {
	return unique_ptr<bt_node<int>>(
		new bt_node<int>(2,
			new bt_node<int>(7,
				new bt_node<int>(2),
				new bt_node<int>(6,
					new bt_node<int>(5),
					new bt_node<int>(11)
				)
			),
			new bt_node<int>(5,
				0,
				new bt_node<int>(9,
					new bt_node<int>(4),
					0
				)
			)
		)
	);
}

#endif // INCLUDED__binary_tree_h
