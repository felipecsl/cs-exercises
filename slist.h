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

#include <memory>

#include <cstdlib>

template <typename T>
class sl_node {
	sl_node *n;
	T v;

public:
	sl_node(T const &value, sl_node *next = 0):
		n(next),
		v(value)
	{
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

using namespace std;
std::unique_ptr<sl_node<int>> build_slist(size_t n, int ubound = 100) {
	if(!n) {
		return std::unique_ptr<sl_node<int>>();
	}
	std::unique_ptr<sl_node<int>> head(
		new sl_node<int>(std::rand() % ubound)
	);

	for(auto node = head.get(); --n; node = node->next()) {
		node->next(
			new sl_node<int>(std::rand() % ubound)
		);
	}

	return head;
}

#endif // INCLUDED__slist_h
