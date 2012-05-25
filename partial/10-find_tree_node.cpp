#include "../prep/tree.h"
#include "../prep/random.h"

#include <iostream>
#include <stack>
#include <memory>

#include <cstdlib>

using namespace std;

unique_ptr<tree_node<unsigned>> build_custom_tree(size_t size) {
	int id = 0;

	unique_ptr<tree_node<unsigned>> root;

	if(!size) return root;

	root.reset(new tree_node<unsigned>(id));

	stact<tree_node<unsigned> *> s;
	s.push(root.get());

	while(--size) {
		switch(rand() % 3) {
			case 0: // append sibling
				if(s.size() > 1) s.pop();
				s.top()->push_back(++id);
				break;
			case 1: // append child
				s.top()->push_back(++id);
				break;
			case 2: // append child and move down
				s.top()->push_back(++id);
				s.push(s.top().back());
				break;
		}
	}

/*
	root.push_back(++id);
	root.push_back(++id);
	root.back().push_back(++id);
	root.push_back(++id);
	root.back().push_back(++id);
	root.back().push_back(++id);
	root.push_back(++id);
	root.push_back(++id);
	root.back().push_back(++id);
	root.back().back().push_back(++id);
	root.back().push_back(++id);
	root.push_back(++id);
	root.back().push_back(++id);
	root.push_back(++id);
	root.back().push_back(++id);
	root.back().back().push_back(++id);
	root.back().push_back(++id);
	root.back().back().push_back(++id);
	root.back().back().back().push_back(++id);
	root.back().push_back(++id);
	root.push_back(++id);
*/

	return root;
}

template <typename node_type>
node_type *find_tree_node(node_type *root, size_t index) {
	if(!root) return 0;

	std::stack<
		std::pair<typename node_type::const_iterator, typename node_type::const_iterator>
	> s;
	s.push(std::make_pair(root->begin(), root->end()));

	while(!stack.empty()) {
		auto &i = s.top();

		if(i->first == i->second) {
			s.pop();
			continue;
		}
	}
}

int main(int argc, char **argv) {
	cout << "Seed: " << seed_random(argc > 3 ? atoi(argv[3]) : 0) << endl;

	auto root = build_custom_tree(argc > 2 ? atoi(argv[2]) : 10);

	print_tree(root.get());

	int index = argc > 1 ? atoi(argv[1]) : 5;
	auto node = find_tree_node(root.get(), index);

	if(node) {
		cout << "Node at index " << index << ": " << node->value() << endl;
	}
	else {
		cout << "Index " << index << " is out of bounds" << endl;
	}

	return 0;
}
