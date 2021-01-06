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


void  solution1(vector<int>& a, int pos, int n, int& mymax, int& mysum) {


	if (pos == n) {
		//cout << mysum << " :" << mymax << endl;
		if (abs(mysum) < mymax) {
			mymax = abs(mysum);
			//cout << "selected " << mymax << endl;
		};
		return;
	}
	else {
		//try  with +
		mysum = mysum + a.at(pos);
		solution1(a, pos + 1, n, mymax, mysum);
		mysum = mysum - a.at(pos);

		//try  with +
		mysum = mysum - a.at(pos);
		solution1(a, pos + 1, n, mymax, mysum);
		mysum = mysum + a.at(pos);
	};

}

int solution1a(vector<int>& a) {
	auto n = a.size();
	auto pos = 0;
	int mymax = 20000 * 100;
	int mysum = 0;
	solution1(a, pos, n, mymax, mysum);
	return mymax;
}


#include <stack>
#include <list>
#include <vector>
#include <limits.h>

int solution(vector<int>& a) {
	int n = a.size();
	if (n == 0) return 0;
	auto stk_sum = new stack<int>;
	auto stk_pos = new stack<int>;

	stk_sum->push(0);
	stk_pos->push(0);
	int sum;
	int pos;

	int  mymax = INT_MAX;

	while (!stk_pos->empty()) {

		pos = stk_pos->top();
		stk_pos->pop();

		sum = stk_sum->top();
		stk_sum->pop();

		auto sump = sum + a.at(pos);
		auto sumn = sum - a.at(pos);

		if (pos == n-1) {
			if (abs(sump) < mymax) mymax = abs(sump);
			if (abs(sumn) < mymax) mymax = abs(sumn);

		}
		else {
			stk_pos->push(pos + 1);
			stk_sum->push(sump);
			stk_pos->push(pos + 1);
			stk_sum->push(sumn);

		}





	}

	return mymax;

}


int main() {

	vector<int> a = { };
	//vector<int> a = { 1,5,2,-2 };
	//vector<int> a = { 1,5 };

	auto res = solution(a);
	cout << res << endl;

}