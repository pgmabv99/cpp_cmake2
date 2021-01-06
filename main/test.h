#pragma once

class test_t {

public :
	test_t() {
		cout << "base construct class test " << endl;
	};	
	~test_t() {
		cout << "base destruct class test " << endl;
	};
	virtual void run() {
		cout << "base run class test " << endl;

	}
protected:
	util utilp = util();
	void* pi;
private:

};


class test_triplets_t :public test_t {
public:
	test_triplets_t::test_triplets_t();
	test_triplets_t::~test_triplets_t();
	void test_triplets_t::run();
private:

};

class test_arr_dist_t :public test_t {
public:
	test_arr_dist_t::test_arr_dist_t();
	test_arr_dist_t::~test_arr_dist_t();
	void test_arr_dist_t::run();
private:

};
