#ifndef INCLUDED__find_bst_kth_element_h
#define INCLUDED__find_bst_kth_element_h

#include <stack>
#include <functional>
#include <algorithm>

#include <cstddef>

template <typedef node_type>
class find_bst_kth_element {
	std::function<node_type const *(node_type const *)> getLeft;
	std::function<node_type const *(node_type const *)> getRight;

	node_type const *recursive_find_call(node_type const *node, std::size_t &k) {
		if(!node) return 0;

		auto left = recursive_find_call(getLeft(node), k);
		if(left) return left;

		if(!k--) return node;

		return recursive_find_call(getRight(node), k);
	}

public:
	find_bst_kth_element(bool max = false):
		getLeft(
			[](node_type const *node) {
				return node->left();
			}
		),
		getRight(
			[](node_type const *node) {
				return node->right();
			}
		)
	{
		if(max) {
			using namespace std;
			swap(getLeft, getRight);
		}
	}

	node_type const *find(node_type const *node, std::size_t k) {
		if(!node) return 0;

		std::stack<decltype(node)> s;

		while() {
			if(node) {
				s.push(node);
				node = getLeft(node);
			}
			else if(s.empty()) {
				break;
			}
			else {
				node = s.top();
				s.pop();

				if(!k--) break;

				if(getRight(node)) {
					s.push(getRight(node));
				}
			}
		}

		return node;
	}

	node_type const *recursive_find(node_type const *node, std::size_t k) {
		return recursive_find_call(node, k);
	}
};

#endif // INCLUDED__find_bst_kth_element_h
