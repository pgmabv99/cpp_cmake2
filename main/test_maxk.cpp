
#include "util.h"
#include "test.h"




struct test_maxki_t {
	list<int>* k_list;
};

void max_k(test_maxki_t* test_maxki_p, vector<int>* in_v, int k) {

	int n = (int)in_v->size();

	test_maxki_p->k_list = new list<int>{};
	test_maxki_p->k_list->push_back(INT_MIN);


	for (auto in = 0; in < n; in++) {

		auto val = in_v->at(in);

		// find the place
		auto inserted = false;
		for (auto k_pos = test_maxki_p->k_list->begin(); k_pos != test_maxki_p->k_list->end(); k_pos++) {

			if (val < *k_pos) {
				//insert before
				test_maxki_p->k_list->insert(k_pos, val);
				inserted = true;
				break;
			}
		}
		// at the end 
		if (!inserted) {
			test_maxki_p->k_list->push_back(val);
		}
		cout << " before truncate" << endl;
		util::print_l(test_maxki_p->k_list);
		//pop front if too long 
		if (test_maxki_p->k_list->size() > k) {
			test_maxki_p->k_list->pop_front();
			cout << " after truncate" << endl;
			util::print_l(test_maxki_p->k_list);
		}



	};
}

test_maxk_t::test_maxk_t() {
	X2_CRT;

	pi  = (void*) new (test_maxki_t);




	cout << "exit test_maxk_t constructor" << endl;
};
test_maxk_t::~test_maxk_t() {
	X2_DST
		test_maxki_t* test_maxki_p = (test_maxki_t*)pi;
	delete(test_maxki_p);
};

void test_maxk_t::run() {
	test_maxki_t* test_maxki_p = (test_maxki_t*)pi;

	vector<int> a = { 1,5,2,-2,7 };
	util::print_v(&a);
	max_k(test_maxki_p, &a, 2);
	util::print_l(test_maxki_p->k_list);

};