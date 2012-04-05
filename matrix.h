#ifndef INCLUDED__matrix_h
#define INCLUDED__matrix_h

#include <vector>

template <typename T>
class matrix {
	typedef std::vector<T> array_type;
	typedef typename array_type::reference reference;
	typedef typename array_type::const_reference const_reference;

	array_type m;
	typename array_type::size_type w;
	typename array_type::size_type h;

public:
	typedef typename array_type::size_type size_type;

	matrix(size_type width, size_type height, T const &value):
		m(width * height, value),
		w(width),
		h(height)
	{
	}

	reference operator()(size_type const x, size_type const y) {
		return m[y * w + x];
	}

	const_reference operator()(size_type const x, size_type const y) const {
		return m[y * w + x];
	}

	size_type const width() const { return w; }
	size_type const height() const { return h; }
};

#endif // INCLUDED__matrix_h
