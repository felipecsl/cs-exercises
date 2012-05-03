#include "../prep/slist.h"
#include "../prep/random.h"

#include <iostream>

#include <cstdlib>

using namespace std;

template <typename node_type>
node_type *recursive_reverse_slist(node_type *node, node_type *prev = 0) {
	if(!node) return prev;

	auto last = recursive_reverse_slist(node->next(), node);
	node->next(prev);

	return last;
}

template <typename node_type>
node_type *reverse_slist(node_type *node) {
	node_type *prev = 0;

	for(node_type *next; node; node = next) {
		next = node->next();
		node->next(prev);
		prev = node;
	}

	return prev;
}

int main(int argc, char **argv) {
	cout << "Seed: " << seed_random(argc > 2 ? atoi(argv[2]) : 0) << endl;

	auto list = build_list(argc > 1 ? atoi(argv[1]) : 10);

	cout << "Input list:" << endl;
	for(auto node = list.get(); node; node = node->next()) {
		cout << ' ' << node->value();
	}
	cout << endl;

	list.reset(reverse_slist(list.release()));
	cout << "Reversed list:" << endl;
	for(auto node = list.get(); node; node = node->next()) {
		cout << ' ' << node->value();
	}
	cout << endl;

	list.reset(recursive_reverse_slist(list.release()));
	cout << "Recursively reversed-back list:" << endl;
	for(auto node = list.get(); node; node = node->next()) {
		cout << ' ' << node->value();
	}
	cout << endl;

	return 0;
}
