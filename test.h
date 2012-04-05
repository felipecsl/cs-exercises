#ifndef INCLUDED__test_h
#define INCLUDED__test_h

class test_suite {
	typedef function<void()> fn_type;
	typedef map<string, fn_type> test_list;

	test_list suite;
	int id;

public:
	test_suite():
		id(0)
	{
	}

	template <typename T>
	int add(string const &name, T testCase) {
		suite[name] = fn_type(testCase);
		return id++;
	}

	void run() {
/*
		for(auto &test: suite) {
/*/
		for(auto i = suite.begin(); i != suite.end(); ++i) {
//*/
			auto &test = *i;

			try {
				test.second();
			}
			catch(exception &e) {
				cerr << "Test " << test.first << " failed ["
					<< typeid(e).name() << "]: " << e.what()
					<< endl;
			}
		}
	}

	static test_suite &singleton() {
		static test_suite instance;
		return instance;
	}
};

template <typename T>
int add_test(string const &name, T test) {
	return test_suite::singleton()
		.add(name, test);
}

#endif // INCLUDED__test_h
