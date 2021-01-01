#include "test02_thr.h"
#include "util.h"
#include <thread>
#include <chrono>
 

 
void test02_thr::test02_thr_run() {
	//to do why static is needed 
	auto n = 55;
	auto thr_list = new list<thread*>;

	for (auto tid = 0; tid < n; tid++) {
		auto thr = new thread(hello,tid);
		thr_list->push_back(thr);
	}
	for (auto thr : *thr_list) {
		thr->join();
	}
	
};

void test02_thr::hello(int tid ) {
	auto n = 10 ;
	for (auto i = 0; i < n; i++) {
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		cout << " tid" << tid << endl;
	}
};
 
//todo pipe results to main thread 