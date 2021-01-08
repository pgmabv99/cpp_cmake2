#include "util.h"
#include "test02_thr.h"
#include "test.h"






class test01 {

private:
	util utilp = util();

public:
	int test1arr(int* alist) {
		auto mysum = 0;
		auto len1 = sizeof(*alist);
		auto len2 = sizeof(alist[0]);

		auto len = len1 / len2;
		for (auto i = 0; i < len; i++) {
			mysum = mysum + alist[i];

		}

		return mysum;
	}


	int test1vec(vector<int>* vlist) {
		auto mysum = 0;



		for (auto a : *vlist) {
			mysum = mysum + a;

		}

		return mysum;
	}

	void test_arr_vec() {
		int alist[] = { 1,2,3 ,4,5 };
		auto* vlist = new vector<int>{ 1, 2, 3, 4, 5 };

		cout << "Hello test." << endl;
		auto res = this->test1arr(alist);
		cout << "res from array " << res << endl;
		auto resv = this->test1vec(vlist);
		cout << "res from vector " << resv << endl;

	}

public:
	void template_test() {
		auto i_lst = new vector<int>{ 0 ,2 };
		auto c_lst = new vector<char>{ 'a','b' };
		//auto f_lst = new vector<float>{ 0.1, 0.2 };
		auto s_lst = new vector<string>{ "aa","bb" };

		util::print_v(i_lst);
		//util::print_v(f_lst);
		util::print_v(c_lst);
		util::print_v(s_lst);


	}
};





//int main()
//{
	//todo
	//cout << "current path " << util::get_current_dir() << endl;
	//test01* ptest1 = new test01();
	//ptest1->triplets_test();
	//ptest1->template_test();

	//auto pt = new test02_thr();
	//pt->test02_thr_run();


	//cout << " =====derived class" << endl;
	//test_triplets_t* test_triplets_p = new test_triplets_t();
	//test_triplets_p->run();
	//delete(test_triplets_p);

	//cout << " =====base class via base ptr" << endl;
	//test_t* test_p = new test_t();
	//test_p->run();
	//delete(test_p);

	//cout << " =====base class via derived ptr" << endl;
	//test_t* test_triplets_p2 = new test_triplets_t();
	//test_triplets_p2->run();
	//delete(test_triplets_p2);

	//test_arr_dist_t* test_arr_dist_p = new test_arr_dist_t();
	//test_arr_dist_p->run();
	//return 0;
//}








list<int>* max_k(vector<int>* in_v, int k) {

	int n = (int) in_v->size();

	list<int>* k_list = new list<int>{};
	k_list->push_back(INT_MIN);

	for (auto in = 0; in < n; in++) {

		auto val = in_v->at(in);

		// find the place
		auto inserted = false;
		for (auto k_pos = k_list->begin(); k_pos != k_list->end(); k_pos++) {

			if (val < *k_pos) {
				//insert before
				k_list->insert(k_pos, val);
				inserted = true;
				break;
			}
		}
		// at the end 
		if (!inserted) {
			k_list->push_back(val);
		}
		cout << " before truncate" << endl;
		util::print_l(k_list);
		//pop front if too long 
		if (k_list->size() > k) {
			k_list->pop_front();
			cout << " after truncate" << endl;
			util::print_l(k_list);
		}



	};
	return k_list;
}





int main() {

	//vector<int> a = { };
	//vector<int> a = { 1,5,2,-2,7 };
	//vector<int> a = { 1,5 };
	//util::print_v(&a);
	//auto res = max_k(&a, 2);
	//util::print_l(res);
	//cout << res << endl;

	auto test_p = new test_hrt_t();
	test_p->run();
	delete(test_p);


}