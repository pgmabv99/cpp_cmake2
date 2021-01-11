
#include "util.h"
#include "test.h"



class junk_t {
public:
	junk_t() { X2_CRT };
	~junk_t() { X2_DST };
};

struct test_uniqueptri_t {
	unique_ptr<junk_t> junk_p;
	shared_ptr<junk_t> junk_p2;
	shared_ptr<junk_t> junk_p3;
};



test_uniqueptr_t::test_uniqueptr_t() {
	X2_CRT;

	pi = (void*) new (test_uniqueptri_t);

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



	cout << "exit test_uniqueptr_t constructor" << endl;
};
test_uniqueptr_t::~test_uniqueptr_t() {
	X2_DST;
	test_uniqueptri_t* test_uniqueptri_p = (test_uniqueptri_t*)pi;
	test_uniqueptri_p->junk_p.reset(nullptr);
	cout << "after reset" << endl;
	delete(test_uniqueptri_p);
};

void test_uniqueptr_t::run() {
	test_uniqueptri_t* test_uniqueptri_p = (test_uniqueptri_t*)pi;


};