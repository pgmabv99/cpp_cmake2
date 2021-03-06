#pragma once
#include "util.h"
#include <typeinfo>

class test_t {

public:
	test_t() {

		X2_CRT

	};
	~test_t() {
		X2_DST
	};
	//virtual void run() {
	//	cout << "base run class test " << endl;

	//}	
	virtual void run() = 0; 

	int sample_public_field =0;

protected:
	util utilp = util();

	// pimpl via void *
	void* pi = nullptr;
	void* pixp = nullptr;

private:

};


// 3 numbers product .find the max
class test_triplets_t :public test_t {
public:
	test_triplets_t::test_triplets_t();
	test_triplets_t::~test_triplets_t();
	void test_triplets_t::run();
private:

};


// 2 arrays : find minmial disatance between 2 elements
class test_arr_dist_t :public test_t {
public:
	test_arr_dist_t::test_arr_dist_t();
	test_arr_dist_t::~test_arr_dist_t();
	void test_arr_dist_t::run();
private:
};

// codility maxsum of list with +1, -1 mulitplies
class test_maxabssum_t :public test_t {
public:
	test_maxabssum_t::test_maxabssum_t();
	test_maxabssum_t::~test_maxabssum_t();
	void test_maxabssum_t::run();
private:
};

// tree traverse
class test_tree_t :public test_t {
public:
	test_tree_t::test_tree_t() {};
	test_tree_t::~test_tree_t() {};
	void test_tree_t::run();
private:
};

// hrt test of 2 selected int = T
class test_hrt_t :public test_t {
public:
	test_hrt_t::test_hrt_t() {};
	test_hrt_t::~test_hrt_t() {};
	void test_hrt_t::run();
private:
};


// unique_ptr ptr
class test_uniqueptr_t :public test_t {
public:
	test_uniqueptr_t::test_uniqueptr_t();
	
	test_uniqueptr_t::~test_uniqueptr_t();
	void test_uniqueptr_t::run();
private:

};

// pimpl ptr
class test_pimpl_t :public test_t {
public:
	test_pimpl_t::test_pimpl_t();
	
	test_pimpl_t::~test_pimpl_t();
	void test_pimpl_t::run();
private:
	//via pimptl via unique ptr
	// todo move to base class
	class impl_t;
	unique_ptr<impl_t> impl_p;
};

// find max k elements
class test_maxk_t :public test_t {
public:
	test_maxk_t::test_maxk_t();
	
	test_maxk_t::~test_maxk_t();
	void test_maxk_t::run();
private:
	class impl_t;
	unique_ptr<impl_t> impl_p;
};

// test lambda
class test_lambda_t :public test_t {
public:
	test_lambda_t::test_lambda_t();
	
	test_lambda_t::~test_lambda_t();
	void test_lambda_t::run();
private:
	class impl_t;
	unique_ptr<impl_t> impl_p;
};