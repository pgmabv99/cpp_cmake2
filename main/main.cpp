#include "util.h"
#include "test.h"



int main() {


	auto test_p = new test_lambda_t();
	test_p->sample_public_field = 99;
	test_p->run();
	delete(test_p);


}