#include "./bst.h"

#include <iostream>

using namespace std;

template <typename node_type>
size_t binary_tree_depth(node_type *node) {
	if(!node) return 0;

	auto left = binary_tree_depth(node->left()) + 1;
	auto right = binary_tree_depth(node->right()) + 1;

	return max(left, right);
}

int main() {
	auto balanced = build_balanced_tree();
	cout << "depth = " << binary_tree_depth(balanced.get())
		<< endl;

	auto unbalanced = build_unbalanced_tree();
	cout << "depth = " << binary_tree_depth(unbalanced.get())
		<< endl;

	return 0;
}
