#include <iostream>
#include <string>

#include <cstdlib>

using namespace std;

template <
	typename fn_output,
	typename char_type = char,
	char_type opening = '(',
	char_type closing = ')'
>
class generate_balanced_parenthesis {
	fn_output out;
	string buffer;
	size_t pairs;

	void generate(size_t open, size_t position) {
		if(position == buffer.size()) {
			out(buffer);
			return;
		}

		if(position < buffer.size() - 1) {
			buffer[position] = opening;
			generate(open + 1, position + 1);
		}
		else {
			assert(open == buffer.size() / 2);
		}

		if(open > 0) {
			buffer[position] = closing;
			generate(open - 1, position + 1);
		}
	}

public:
	generate_balanced_parenthesis(fn_output out, size_t pairs):
		out(out),
		buffer(pairs * 2),
		pairs(pairs)
	{
		assert(pairs > 0);
	}

	void operator () {
		generate(0, 0);
	}
};
void generate_balanced_parenthesis() {
	vector<char> buffer(pairs * 2);
}

template <typename fn_output>
void  {
	vector<char> buffer(pairs * 2);
}

int main(int argc, char **argv) {
	auto out = [](string const &s) { cout << s << endl; };

	generate_balanced_parenthesis<decltype(out)>(
		out, argc > 1 ? atoi(argv[1]) : 3
	)();

	return 0;
}
