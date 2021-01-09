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
	virtual void run() {
		cout << "base run class test " << endl;

	}
protected:
	util utilp = util();
	void* pi = nullptr;
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

// find max k elements
class test_maxk_t :public test_t {
public:
	test_maxk_t::test_maxk_t();
	
	test_maxk_t::~test_maxk_t();
	void test_maxk_t::run();
private:
};
