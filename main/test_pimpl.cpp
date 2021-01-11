
#include "util.h"
#include "test.h"



class junk_t {
public:
	junk_t() { X2_CRT };
	~junk_t() { X2_DST };
};

struct test_pimpli_t {
	unique_ptr<junk_t> junk_p;
	shared_ptr<junk_t> junk_p2;
	shared_ptr<junk_t> junk_p3;
};

class test_pimpl_t::impl_t {

	test_pimpl_t::impl_t() {
		X2_CRT;
	}	
	~impl_t() {
		X2_DST;
	}
	

};

test_pimpl_t::test_pimpl_t() {
	X2_CRT;

	pi = (void*) new (test_pimpli_t);

	if (true)
	{
		unique_ptr<junk_t> up = make_unique<junk_t>();
		cout << "up" << up << endl;
		unique_ptr<junk_t> up2 = move(up);
		cout << "up and up2 after move " << up << ":" << up2 << endl;
		//up2.reset(nullptr);

	}
	if (true)
	{
		shared_ptr<junk_t> sp2 = nullptr;
		if (true)
		{
			shared_ptr<junk_t> sp = make_shared<junk_t>();
			cout << "sp" << sp << endl;
			sp2 = sp;
			sp2.reset();
			cout << "sp and s2 after copy " << sp << ":" << sp2 << endl;
		}

	}



	cout << "exit test_pimpl_t constructor" << endl;
};
test_pimpl_t::~test_pimpl_t() {
	X2_DST;
	test_pimpli_t* test_pimpli_p = (test_pimpli_t*)pi;
	test_pimpli_p->junk_p.reset(nullptr);
	cout << "after reset" << endl;
	delete(test_pimpli_p);
};

void test_pimpl_t::run() {
	test_pimpli_t* test_pimpli_p = (test_pimpli_t*)pi;


};