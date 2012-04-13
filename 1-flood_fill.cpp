#include "./color.h"
#include "./matrix.h"

#include <utility>
#include <stack>

#include <cassert>

using namespace std;

struct flood_fill {
	typedef bitmap_paint bitmap_type;
	typedef bitmap_type::color color;
	typedef bitmap_type::dimension dimension;

private:
	bitmap_type &bitmap;

	void recursive_fill(dimension x, dimension y, color c, color bg) {
		dot(x, y, c);

		if(x > 0 && pick(x - 1, y) == bg) recursive_fill(x - 1, y, c, bg);
		if(y > 0 && pick(x, y - 1) == bg) recursive_fill(x, y - 1, c, bg);
		if(x < bitmap.width() - 1 && pick(x + 1, y) == bg) recursive_fill(x + 1, y, c, bg);
		if(y < bitmap.height() - 1 && pick(x, y + 1) == bg) recursive_fill(x, y + 1, c, bg);
	}

public:
	flood_fill(bitmap_type &bitmap):
		bitmap(bitmap)
	{
	}

	void fill(dimension x, dimension y, color c, bool recursive = false) {
		assert(x < bitmap.width() && y < bitmap.height());

		auto bg = bitmap(x, y);
		if(bg == c) return;

		if(recursive) {
			recursive_fill(x, y, c, bg);
			return;
		}

		stack<coord> s;
		s.push(make_pair(x, y));

		while(!s.empty()) {
			x = s.top().first;
			y = s.top().second;
			s.pop();

			dot(x, y, c);

			if(x > 0 && pick(x - 1, y) == bg) s.push(make_pair(x - 1, y));
			if(y > 0 && pick(x, y - 1) == bg) s.push(make_pair(x, y - 1));
			if(x < bitmap.width() - 1 && pick(x + 1, y) == bg) s.push(make_pair(x + 1, y));
			if(y < bitmap.height() - 1 && pick(x, y + 1) == bg) s.push(make_pair(x, y + 1));
		}
	}
};

int main() {
	// TODO: Implement test case
	return 0;
}
