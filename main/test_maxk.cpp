
#include "util.h"
#include "test.h"



class junk_t {
public:
	junk_t() { X2_CRT };
	~junk_t() { X2_DST };
};

struct test_maxki_t {
	list<int>* k_list;
	unique_ptr<junk_t> junk_p;
	shared_ptr<junk_t> junk_p2;
	shared_ptr<junk_t> junk_p3;
};

void max_k(test_maxki_t* test_maxki_p, vector<int>* in_v, int k) {

	int n = (int)in_v->size();

	test_maxki_p->k_list = new list<int>{};
	test_maxki_p->k_list->push_back(INT_MIN);

	test_maxki_p->junk_p.reset(new (junk_t));
	test_maxki_p->junk_p2.reset(new (junk_t));
	test_maxki_p->junk_p3 = test_maxki_p->junk_p2;

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



	cout << "exit test_maxk_t constructor" << endl;
};
test_maxk_t::~test_maxk_t() {
	X2_DST
		test_maxki_t* test_maxki_p = (test_maxki_t*)pi;
	test_maxki_p->junk_p.reset(nullptr);
	cout << "after reset" << endl;
	delete(test_maxki_p);
};

void test_maxk_t::run() {
	test_maxki_t* test_maxki_p = (test_maxki_t*)pi;

	vector<int> a = { 1,5,2,-2,7 };
	util::print_v(&a);
	max_k(test_maxki_p, &a, 2);
	util::print_l(test_maxki_p->k_list);

};