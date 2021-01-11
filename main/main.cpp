#include "util.h"
#include "test.h"



int main() {


	auto test_p = new test_uniqueptr_t();
	test_p->run();
	delete(test_p);


}