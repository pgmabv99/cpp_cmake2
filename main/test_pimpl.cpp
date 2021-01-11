
#include "util.h"
#include "test.h"




class test_pimpl_t::impl_t {
public :
	impl_t() {
		X2_CRT;
	}	
	~impl_t() {
		X2_DST;
	}
 
	int junk =0;

};

test_pimpl_t::test_pimpl_t() {
	X2_CRT;
	this->impl_p= make_unique< impl_t>();


	this->impl_p->junk = 99;
	cout << "test_pimpl_t::constructor set impl_p  attibute " << this->impl_p->junk << endl;

};
test_pimpl_t::~test_pimpl_t() {
	X2_DST;
};

void test_pimpl_t::run() {
	cout << "test_pimpl_t::run() get impl_p attribute " << this->impl_p->junk << endl;
};