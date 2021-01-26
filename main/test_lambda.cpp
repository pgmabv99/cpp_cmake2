#include "util.h"
#include "test.h"

class test_lambda_t::impl_t {
private:
	string fname = "hello";

};

test_lambda_t::test_lambda_t() {
	X2_CRT;
	impl_p = make_unique < test_lambda_t::impl_t>();
};

test_lambda_t::~test_lambda_t() {
	X2_DST;

}

bool   fun_comp(int a, int b) {

	auto  i = 1;
	return (abs(a) < abs(b));
}

void test_lambda_t::run() {
	cout << "lambda run" << endl;
	int z = 100;

	auto lmb1 = [z](int a, int b) {
		auto x = a + b + z;
		cout << "lmb1 called " << x << endl;
		return x;
	};
	lmb1(2, 3);

	auto lmb2 = [](int a) {

		cout << "lmb2 called " << a << endl;
	};
	lmb1(2, 3);

	auto lmb_comp = [](auto a, auto b) { return(abs(a) < abs(b)); };

	auto lst1 = new vector<int>({ 1,2 });
	lst1->push_back(-3);

	int ar1[] = { 1,2,3 };

	cout << " iter via begin/end" << endl;
	for (auto it = lst1->begin(); it != lst1->end(); it++) {
		lmb2(*it);
	}

	cout << " iter via range" << endl;
	for (const auto& v : *lst1) {
		lmb2(v);
	}

	cout << " iter via for_each with lambda defined previuosly " << endl;
	for_each(lst1->begin(), lst1->end(), lmb2);

	cout << " iter via for_each with lambda defined inline  " << endl;
	for_each(lst1->begin(), lst1->end(), [](int a) {cout << a * 10 << endl; });

	cout << "sort with default comp" << endl;
	sort(lst1->begin(), lst1->end());
	for (auto v : *lst1) cout << v << endl;



	cout << "sort with lamda predefined override  comp" << endl;
	sort(lst1->begin(), lst1->end(), lmb_comp);
	for (auto v : *lst1) cout << v << endl;

	cout << "sort with non lambda function  predefined override  comp" << endl;
	sort(lst1->begin(), lst1->end(), fun_comp);
	for (auto v : *lst1) cout << v << endl;

	// !!!! this is the real value of lambda . pass the function and the data handle !!!!!!!!!!!!!!!!!
	// for example you can pass the handle to the current sort collation object
	cout << "sort with lamda inline override  comp passing this !!!" << endl;
	sort(lst1->begin(), lst1->end(),
		[this]  // 
	(auto a, auto b) {
			cout << " access this of caller from inline lamda " << this->sample_public_field << endl;
			return (abs(a) < abs(b));
		});
	for (auto v : *lst1) cout << v << endl;


}