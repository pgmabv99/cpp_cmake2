#include "test01.h";
#include <thread>;

#include <chrono>;


class test02_thr {

public:
	void test_thr() {
		this->hello();
	}

private:
	void hello() {
		auto n = 100;
		for (auto i = 0; i < n; i++) {
			std::this_thread::sleep_for(std::chrono::microseconds(1000));
			cout << " i " << i << endl;
		}
	}
};