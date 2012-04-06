#ifndef INCLUDED__slist_h
#define INCLUDED__slist_h

#pragma message "\n\
\n\
******************************************\n\
THIS CODE SHOULD NOT be used in production\n\
it's very limited and NOT EXCEPTION SAFE\n\
it may also contain UNDEFINED BEHAVIOR\n\
it's only intended for exercising purposes\n\
******************************************\n\
"

#include <initializer_list>
#include <stdexcept>

template <typename T>
class sl_node {
	sl_node *n;
	T v;

public:
	sl_node(T const &value, sl_node *next = 0):
		n(next),
		v(v)
	{
	}

	sl_node(std::initializer_list<T> list):
		n(0),
		v(*std::begin(list))
	{
		sl_node *node = this;

		for(auto i = std::begin(list); i != std::end(list); ++i) {
			node->n = new sl_node(*i);
			node = node->n;
		}
	}

	~sl_node() {
		delete n;
	}

	sl_node const *next() const { return n; }
	sl_node *next() { return n; }
	sl_node *next(sl_node *next) { return n = next; }

	T const &value() const { return v; }
	T &value() { return v; }
};

#endif // INCLUDED__slist_h
