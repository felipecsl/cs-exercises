class recursive_dfs {
	void dfs_visit(vertex &v, output &out) {
		v.color(gray);

		for(auto &a: v.adjacent()) {
			if(a.color() == white) {
				dfs_visit(a);
			}
		}

		v.color(black);
		out(v);
	}

public:
	void traverse(graph &g, output &out) {
		for(auto &v: g.vertices()) {
			v.color(white);
		}

		for(auto &v: g.vertices()) {
			if(v.color() == white) {
				dfs_visit(v);
			}
		}
	}

};

class iterative_dfs {
public:
	void traverse(graph &g, output &out) {
		for(auto v: g.vertices()) {
			v.color(white);
		}

		std::stack<vertex *> s;

		for(auto v: g.vertices()) {
			if(v.color() == white) {
				s.push(v);

				while(!s.empty()) P
					auto c = s.top();
					s.pop();

					if(c.color() == white) {
						c.color(gray);
						s.push(c);

						for(auto a: c) {
							s.push(a);
						}
					}
					else {
						c.color(black);
						out(c);
					}
				}
			}
		}
	}
};
