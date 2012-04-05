#include "./color.h"
#include "./matrix.h"

#include <utility>
#include <stack>

#include <cassert>

using namespace std;

class bitmap_paint {
	typedef matrix<color> bitmap_type;

public:
	typedef bitmap_type::size_type size_type;
	typedef size_type dimension;
	typedef pair<dimension, dimension> coord;

private:
	bitmap_type bitmap;

	void recursive_flood_fill(dimension x, dimension y, color c, color bg) {
		point(x, y, c);

		if(x > 0 && pick(x - 1, y) == bg) recursive_flood_fill(x - 1, y, c, bg);
		if(y > 0 && pick(x, y - 1) == bg) recursive_flood_fill(x, y - 1, c, bg);
		if(x < bitmap.width() - 1 && pick(x + 1, y) == bg) recursive_flood_fill(x + 1, y, c, bg);
		if(y < bitmap.height() - 1 && pick(x, y + 1) == bg) recursive_flood_fill(x, y + 1, c, bg);
	}

	void recursive_edge_fill(matrix<bool> mark, dimension x, dimension y, color c, color bg) {
		mark(x, y) = true;

		if(pick(x, y) != bg) {
			point(x, y, c);
			return;
		}

		if(x > 0 && !mark(x - 1, y)) recursive_edge_fill(mark, x - 1, y, c, bg);
		if(y > 0 && !mark(x, y - 1)) recursive_edge_fill(mark, x, y - 1, c, bg);
		if(x < bitmap.width() - 1 && !mark(x + 1, y)) recursive_edge_fill(mark, x + 1, y, c, bg);
		if(y < bitmap.height() - 1 && !mark(x, y + 1)) recursive_edge_fill(mark, x, y + 1, c, bg);
	}

public:
	bitmap_paint(size_type width, size_type height, color bg = color::black()):
		bitmap(width, height, bg)
	{
	}

	void point(dimension x, dimension y, color c) { bitmap(x, y) = c; }
	color const pick(dimension x, dimension y) const { return bitmap(x, y); }

	void flood_fill(dimension x, dimension y, color c, bool recursive = false) {
		assert(x < bitmap.width() && y < bitmap.height());

		auto bg = bitmap(x, y);
		if(bg == c) return;

		if(recursive) {
			recursive_flood_fill(x, y, c, bg);
			return;
		}

		stack<coord> s;
		s.push(make_pair(x, y));

		while(!s.empty()) {
			x = s.top().first;
			y = s.top().second;
			s.pop();

			point(x, y, c);

			if(x > 0 && pick(x - 1, y) == bg) s.push(make_pair(x - 1, y));
			if(y > 0 && pick(x, y - 1) == bg) s.push(make_pair(x, y - 1));
			if(x < bitmap.width() - 1 && pick(x + 1, y) == bg) s.push(make_pair(x + 1, y));
			if(y < bitmap.height() - 1 && pick(x, y + 1) == bg) s.push(make_pair(x, y + 1));
		}
	}

	void edge_fill(dimension x, dimension y, color c, bool recursive = false) {
		assert(x < bitmap.width() && y < bitmap.height());

		auto bg = bitmap(x, y);

		matrix<bool> mark(bitmap.width(), bitmap.height(), false);

		if(recursive) {
			recursive_edge_fill(mark, x, y, c, bg);
			return;
		}

		stack<coord> s;
		s.push(make_pair(x, y));

		while(!s.empty()) {
			x = s.top().first;
			y = s.top().second;
			s.pop();

			mark(x, y) = true;

			if(pick(x, y) != bg) {
				point(x, y, c);
			}

			if(x > 0 && !mark(x - 1, y)) s.push(make_pair(x - 1, y));
			if(y > 0 && !mark(x, y - 1)) s.push(make_pair(x, y - 1));
			if(x < bitmap.width() - 1 && !mark(x + 1, y)) s.push(make_pair(x + 1, y));
			if(y < bitmap.height() - 1 && !mark(x, y + 1)) s.push(make_pair(x, y + 1));
		}
	}
};

int main() {
	// TODO: Implement test case
	return 0;
}
