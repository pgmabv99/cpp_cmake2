
#include "util.h"
#include "test.h"


class test_maxk_t::impl_t {
public:
	impl_t() {
		X2_CRT;
	}
	~impl_t() {
		X2_DST;
	}

	unique_ptr<list<int>> k_list = nullptr;
	void max_k(unique_ptr<vector<int>>& in_v, int k);

};


void test_maxk_t::impl_t::max_k(unique_ptr<vector<int>>& in_v, int k) {

	int n = (int)in_v->size();

	this->k_list->push_back(INT_MIN);


	for (auto in = 0; in < n; in++) {

		auto val = in_v->at(in);

		// find the place
		auto inserted = false;
		for (auto k_pos = this->k_list->begin(); k_pos != this->k_list->end(); k_pos++) {

			if (val < *k_pos) {
				//insert before
				this->k_list->insert(k_pos, val);
				inserted = true;
				break;
			}
		}
		// at the end 
		if (!inserted) {
			this->k_list->push_back(val);
		}
		cout << " before truncate" << endl;
		util::print_col(this->k_list);
		//pop front if too long 
		if (this->k_list->size() > k) {
			this->k_list->pop_front();
			cout << " after truncate" << endl;
			util::print_col(this->k_list);
		}



	};
}

test_maxk_t::test_maxk_t() {
	X2_CRT;
	impl_p = make_unique<impl_t>();
	impl_p->k_list = unique_ptr<list<int>>( new list<int>());
};
test_maxk_t::~test_maxk_t() {
	X2_DST;
};


void test_maxk_t::run() {


	auto as = shared_ptr<vector<int>>(new vector<int>{ 1,2,3, -1,-5 });
	auto au = unique_ptr<vector<int>>(new vector<int>{ 1,2,3, -1,-5 });

	util::print_col(au);
	util::print_col(as);


	impl_p->max_k( au, 2);
	util::print_col(impl_p->k_list);
};