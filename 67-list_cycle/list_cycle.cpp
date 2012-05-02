#include "../prep/slist.h"

#include "../67-list_cycle/list_cycle.h"

#include <iostream>
#include <memory>

#include <cassert>

using namespace std;

int main() {
	size_t size = 0;
	size_t cycle = 0;

	if(!(cin >> size) || !(cin >> cycle)) {
		return 1;
	}

	cout << "size = " << size << endl
		<< "cycle = " << cycle << endl;

	if(size < 1) {
		cout << "The list must have at least one element" << endl;
		return 2;
	}

	if(cycle >= size) {
		cout << "The cycle must occur in a valid element" << endl;
		return 3;
	}

	auto head = make_cyclic_list(size, cycle);
	print_list(head.get(), size, "Cyclic list");

	auto cyclic = break_cycle(head);
	print_list(head.get(), "Non-cyclic list");

	return 0;
}
